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


char* gets_s(char* a) {
  char * ret = fgets(a, NA*3, stdin);

  if (ret) {
    size_t sz = strlen(a);
    if (sz > 0) a[sz - 1] = 0;
    else a[0] = 0;
  }

  return ret;
}


struct cmp_str{
  bool operator() (const char* pa, const char* pb) const {
    return strcmp(pa, pb) < 0;
  }
};


char words[NW][NA] = {0};
std::map<char *, int, cmp_str> m[NA];
std::vector<int>  wordbag[NA];
std::vector<int> graph[NW];


int doublet(int a, int b, int len) {
  int c = 0;
  for (int i=0; i<len; ++i) {
    if (words[a][i] != words[b][i]) ++c;

    if (c > 1) return 0;
  }
  return c==1;
}


void build_graph() {
  for (int i=1; i<NA; ++i) {
    int sz = wordbag[i].size();

    for (int j=0; j<sz; ++j) {
      for (int k=j+1; k<sz; ++k) {
        int p = wordbag[i][j];
        int q = wordbag[i][k];
        if (doublet(p, q, i)) {
          graph[p].push_back(q);
          graph[q].push_back(p);
        }
      }
    }
  }

}


void calc_graph() {
  for (int i=1; i<NA; ++i) {
    int sz = i;
    std::vector<int> &grp = wordbag[i];

    std::map<std::string, std::vector<int> > tm;

    for (std::vector<int>::iterator git=grp.begin(); git!=grp.end(); ++git) {
      int widx = *git;
      std::string w(words[widx]);

      for (int i=0; i<sz; ++i) {
        std::string tw(w);
        tw[i] = '*';
        tm[tw].push_back(widx);
      }
    }

    for (std::vector<int>::iterator git=grp.begin(); git!=grp.end(); ++git) {
      int widx = *git;
      std::string w(words[widx]);

      for (int i=0; i<sz; ++i) {
        std::string tw(w);
        tw[i] = '*';

        std::vector<int> &tv = tm[tw];

        for (std::vector<int>::iterator tvit=tv.begin(); tvit!=tv.end(); ++tvit) {
          int neigh = *tvit;
          if (neigh != widx) {
            graph[widx].push_back(neigh);
          }
        }

      }
    }


  }
}

void look_up(int a, int b) {
  std::deque<int> q;
  int bt_map[NW];
  for (int i=0; i<NW; ++i) bt_map[i] = -2;

  q.push_back(a);
  bt_map[a] = -1;//mark start of look up
  
  int from, to;

  bool found = false;
  while(q.size() && !found) {
    from = q.front();
    q.pop_front();

    for (int i=0; i<graph[from].size(); ++i) {
      to = graph[from][i];

      if (bt_map[to] == -2) {
        bt_map[to] = from;
        q.push_back(to);

        if (to == b) {
          found = true;
          break;
        }
      }
    }
  }


  if (!found) {
    printf("No solution.\n");
  }
  else {
    int p=b;
    while (p >= 0) {
      printf("%s\n", words[p]);
      p = bt_map[p];
    }
  }
}

int main() {
  int ncase = -1;
  clock_t t = clock();
  
  int ncount = 0;
  while(gets_s(words[ncount])) {
    int sz = strlen(words[ncount]);
    if (sz == 0) break;

    m[sz][words[ncount]] = ncount;
    wordbag[sz].push_back(ncount);
  
    ++ncount;
  }

  t = clock() - t;
  //printf("took %lu ticks\n", t);

  t = clock();
  build_graph();
  t = clock() - t;
  //printf("took %lu ticks\n", t);

  char a[NA], b[NA];
  while (scanf("%s %s", a, b) == 2) {
    ++ncase;
    if (ncase) printf("\n");

    if (strlen(a) != strlen(b)) {
      printf("No solution.\n");
    }
    else {
      int x = m[strlen(a)][a];
      int y = m[strlen(b)][b];
      look_up(y, x);
    }      
  }

}
