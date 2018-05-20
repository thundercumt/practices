#include <map>
#include <set>
#include <vector>
#include <deque>
#include <string>

#include <cstdio>
#include <cassert>
#include <cstring>

const int N = 250;
const int MAX_AUTH = 10000;

int count = 0;
std::map<std::string, int> authors;
char scores[MAX_AUTH] = {0};


class graph {
public:
  void connect(int i, int j) {
    if (!data.count(i)) data.insert(std::pair<int, std::set<int> >(i, std::set<int>()));
    if (!data.count(j)) data.insert(std::pair<int, std::set<int> >(j, std::set<int>()));
    data[i].insert(j);
    data[j].insert(i);
  }

  bool connected(int i, int j) {
    return data[i].count(j);
  }

  void connections(int i, std::vector<int>& v) {
    for(std::set<int>::iterator it = data[i].begin(); it!=data[i].end(); ++it) {
      //printf("found a neighbor %d\n", *it);
      if (scores[*it] == -1)
        v.push_back(*it);
    }
  }

  void clear() {
    data.clear();
  }
  
private:
  std::map<int, std::set<int> > data;
};


graph co_author;

int add_author(const char* name) {
  std::map<std::string, int>::iterator it = authors.find(name);
  if (it != authors.end()) {
    return it->second;
  }
  else {
    int idx = count;
    authors.insert(std::pair<std::string, int>(name, count++));
    return idx;
  }
}


void parse_paper(char* paper, int sz) {
  char* beg = paper;
  char* beg1;
  char* stop;

  char* end = strchr(paper, ':');
  
  assert(end - paper < sz);

  
  std::vector<int> paper_authors;
  while (beg < end) {

    char name[261] = {0};

    stop = strchr(beg, ',');
    *stop = 0;
    strcpy(name, beg);

    strcat(name, ", ");

    beg = stop + 2;
    stop = strchr(beg, ',');

    if (!stop) stop = strchr(beg, ':');
    *stop = 0;

    strcat(name, beg);
    
    int idx = add_author(name);
    //printf("%d->%s\n", idx, name);
    paper_authors.push_back(idx);

    beg = stop + 2;
  }
  
  assert(paper_authors.size() > 0);

  size_t cnt = paper_authors.size();
  int from, to;
  for (int i=0; i<cnt; ++i) {
    from = paper_authors[i];
    for (int j=i+1; j<cnt; ++j) {
      to = paper_authors[j];
      co_author.connect(from, to);
    }
  }
}


void calculate() {
  int origin = authors.count("Erdos, P.") ? authors["Erdos, P."] : -1;

  std::deque<int> cand;
  if (origin >= 0) {
    scores[origin] = 0;
    cand.push_back(origin);
  }

  int n = count;
  int dist;
  int auth;
  std::vector<int> neighbors;
  int t;
  
  while(cand.size()) {
    auth = cand.front();
    cand.pop_front();

    //printf("calculating %d out of %d authors\n", auth, n);
    
    dist = scores[auth] + 1;

    neighbors.clear();
    co_author.connections(auth, neighbors);
    
    for (int i=0; i<neighbors.size(); ++i) {
      t = neighbors[i];
      if (scores[t] < 0) {
        scores[t] = dist;
        cand.push_back(t);
      }
    }
  }
}


int main() {
  int p, n, i, j;
  char buf[N+1];
  int len;
  int case_num = 0;

  while (scanf("%d%d", &p, &n) == 2) {
    ++case_num;
    
    if (!p && !n) break;

    authors.clear();
    memset(scores, -1, MAX_AUTH);
    co_author.clear();

    fgets(buf, N, stdin);//eats trailing \n

    for (i=0; i<p; ++i) {
      fgets(buf, N, stdin);
      parse_paper(buf, strlen(buf));
    }

    calculate();
    
    printf("Database #%d\n", case_num);
    for (i=0; i<n; ++i) {
      fgets(buf, N, stdin);
      len = strlen(buf);
      buf[len - 1] = 0;//the \n char at the end

      std::string auth(buf, len - 1);
      if (authors.count(auth) && scores[authors[auth]] >= 0) {
        printf("%s: %d\n", buf, scores[authors[auth]]);
      }
      else {
        printf("%s: %s\n", buf, "infinity");
      }
    }

    printf("\n");
    
  }

  return 0;
}
