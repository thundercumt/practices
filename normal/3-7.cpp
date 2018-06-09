#include <cstring>
#include <cstdio>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>

const int NA = 17;
const int NW = 25160;
const int NR = 1024000;

struct link {
  int i;
  link *next;
};

struct node {
  char *pword;
  link *near;
};

node graph[NW] = {0};
int ncount = 0;

link link_pool[NR];
int rcount = 0;

char words[NW][NA] = {0};

struct cmp_str{
  bool operator() (const char* pa, const char* pb) const {
    return strcmp(pa, pb) < 0;
  }
};

std::map<char *, int, cmp_str> m;
std::map<int, std::set<int> > wordbag;


void clear() {
  m.clear();
  wordbag.clear();
  memset(graph, 0, sizeof(node) * NW);
  memset(link_pool, 0, sizeof(link) * NR);
  memset(words, 0, NW * NA);
  ncount = 0;
  rcount = 0;
}

link* new_link(int i) {
  int r = rcount++;
  link_pool[r].i = i;
  link_pool[r].next = 0;
  return &link_pool[r];
}

int new_word(char * s) {
  if (m.count(s)) return m[s];

  int sz = strlen(s);
  int r = ncount++;

  strcpy(words[r], s);
  m[words[r]] = r;
  graph[r].pword = words[r];
  graph[r].near = 0;

  if (wordbag[sz].size() > 0) {
    std::set<int>& cand = wordbag[sz];
    /**
    for(std::set<int>::iterator it = cand.begin(); it != cand.end();  ++it) {

      char* a = graph[*it].pword;
      if (distance(s, a) == 1) {
        link* ln = new_link(r);
        if (graph[*it].near == 0) graph[*it].near = ln;
        else {
          ln->next = graph[*it].near;
          graph[*it].near = ln;
        }

        ln = new_link(*it);
        if (graph[r].near == 0) graph[r].near = ln;
        else {
          ln->next = graph[r].near;
          graph[r].near = ln;
        }
      }
      
    }
    */
  }

  wordbag[sz].insert(r);
  return r;
}

void calc_graph() {
  for (std::map<int, std::set<int> >::iterator it=wordbag.begin(); it != wordbag.end(); ++it) {
    int sz = it->first;
    std::set<int> &grp = it->second;

    std::map<std::string, std::vector<int> > tm;

    for (std::set<int>::iterator git=grp.begin(); git!=grp.end(); ++git) {
      int widx = *git;
      std::string w(graph[widx].pword);

      for (int i=0; i<sz; ++i) {
        std::string tw(w);
        tw[i] = '*';
        tm[tw].push_back(widx);
      }
    }

    for (std::set<int>::iterator git=grp.begin(); git!=grp.end(); ++git) {
      int widx = *git;
      std::string w(graph[widx].pword);

      for (int i=0; i<sz; ++i) {
        std::string tw(w);
        tw[i] = '*';

        std::vector<int> &tv = tm[tw];

        for (std::vector<int>::iterator tvit=tv.begin(); tvit!=tv.end(); ++tvit) {
          int neigh = *tvit;
          if (neigh != widx) {

            link *ln = new_link(neigh);
            
            if (graph[widx].near == 0) {
              graph[widx].near = ln;
            }
            else {
              ln->next = graph[widx].near;
              graph[widx].near = ln;
            }
          }
        }

      }
    }


  }
}
   


void look_up(int a, int b, std::deque<int>& q, std::vector<int>& bt_map) {
  q.clear();
  bt_map.clear();
  bt_map.resize(ncount);

  q.push_back(a);
  bt_map[a] = -1;//mark start of look up
  
  int from, to;
  link *pl;

  if (a==b) return;
  
  while(q.size()) {
    from = q.front();
    q.pop_front();

    for (pl=graph[from].near; pl; pl=pl->next) {
      to = pl->i;

      if (bt_map[to] == 0) {
        bt_map[to] = from;
        q.push_back(to);

        if (to == b) return;
      }
    }
    
  }
}


void output(int a, int b, std::vector<int>& bt) {
  std::vector<int> track;
  int p;

  p = b;
  while (p >= 0) {
    track.push_back(p);
    p = bt[p];
  }

  for (std::vector<int>::reverse_iterator it=track.rbegin(); it != track.rend(); ++it) {
    printf("%s\n", graph[*it].pword);
  }
}

int main() {
  char buf[NA * 3] = {0};
  int ncase = -1;

  
  while (gets(buf)) {
    clear();
    
    clock_t start_t = clock();

    new_word(buf);
    while(gets(buf)) {
      if (strlen(buf) == 0) break;

      new_word(buf);
    }

    calc_graph();

    
    clock_t end_t = clock();
    //printf("adding dictionary took %lu.%lu secs\n", (end_t - start_t) / CLOCKS_PER_SEC, (end_t - start_t) % CLOCKS_PER_SEC);

    while (gets(buf)) {
      ++ncase;
      if (ncase) printf("\n");

      
      char * stop = strchr(buf, ' ');
      *stop = 0;

      char *a = buf;

      stop += 1;
      char *b = stop;

      if (strlen(a) != strlen(b)) {
        printf("No solution.\n");
      }
      else {
        int x = m[a];
        int y = m[b];
        std::deque<int> q;
        std::vector<int> bt;
        look_up(x, y, q, bt);
        //output
        output(x, y, bt);
      }
      
      
    }
    
  }

}
