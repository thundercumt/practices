#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

enum { N = 26, NW = 16 };

char cypher[N] = {0};
char decypher[N] = {0};

set<string> puzzle;
multimap<int, string> dict_by_len;
map<string, int> dict;

static int do_crypt(const string& sent, char* cypher, set<string>::iterator begin, set<string>::iterator end);

void crypt(const string& sent) {
  puzzle.clear();

  for(map<string, int>::iterator it=dict.begin(); it!=dict.end(); ++it) {
    it->second = 0;
  }

  string::const_iterator beg = sent.begin();
  string::const_iterator end = sent.end();
  string::const_iterator stop;
  
  for(; beg != end; ) {
    stop = beg;
    while(stop != end && isalpha(*stop)) ++stop;
    puzzle.insert(string(beg, stop));
    beg = stop;
    while(beg != end && isspace(*beg)) ++beg;
  }

  char cypher[N] = {0};
  set<string>::iterator it = puzzle.begin();
  set<string>::iterator end_of_puzzle = puzzle.end();
  if (!do_crypt(sent, cypher, it, end_of_puzzle)) {
    for (int i=0; i<sent.size(); ++i) {
      if (sent[i] != ' ') cout << '*';
      else cout << sent[i];
    }
    cout << '\n';
  }

  //cout << '\n';//delete me after debug
}

void candidate(const string& crypt_word, vector<string> &v) {
  typedef multimap<int, string>::const_iterator IT;
  pair<IT,IT> range = dict_by_len.equal_range(crypt_word.size());
  IT it = range.first, end = range.second;
  for (; it!=end; ++it) {
    if (dict[it->second] == 0) {
      v.push_back(it->second);
    }
  }
}

int do_crypt(const string& sent, char* cypher, set<string>::iterator begin, set<string>::iterator end) {
  if (begin == end) {
    for (int i=0; i<sent.size(); i++) {
      if (sent[i] != ' ') cout << cypher[sent[i]-'a'];
      else cout << ' ';
    }
    cout << '\n';
    return 1;
  }

  set<string>::iterator begin_next(begin);
  ++begin_next;

  string w = *begin;

  vector<string> cand;
  candidate(w, cand);

  string a;
  vector<char> alpha_q;
  for (int i=0; i<cand.size(); ++i) {
    a = cand[i];

    assert(a.size() == w.size());

    for (int j=0; j<a.size(); ++j) {
      //cout << cypher[w[j]-'a'] << endl;
      
      if (cypher[w[j]-'a'] == a[j] ) continue;

      else if (cypher[w[j]-'a'] == 0) {
        alpha_q.push_back(w[j]);
        cypher[w[j]-'a'] = a[j];
      }

      else {
        //conflict with previously specified cypher
        goto next_candidate;
      }
    }

    if (dict[a] == 0) {
      //cout << "trying a=" << a << endl;
      dict[a] = 1;
      if (do_crypt(sent, cypher, begin_next, end)) return 1;
      dict[a] = 0;
    }
    else {
      if (do_crypt(sent, cypher, begin_next, end)) return 1;
    }
    

  next_candidate:
    for (int k=0; k<alpha_q.size(); ++k) {
      cypher[alpha_q[k]-'a'] = 0;
    }
    alpha_q.clear();
  }
  
  return 0;
}

int main() {
  int n, i;
  string s;

  cin >> n;

  for (i=0; i<n; i++) {
    cin >> s;
    dict.insert(pair<string, int>(s, 0));
    dict_by_len.insert(pair<int, string>(s.size(), s));
  }
  getline(cin, s);//trailing \n

  while (getline(cin, s)) {
    memset(cypher, 0, N);
    memset(decypher, 0, N);
    crypt(s);
  }

  return 0;
}
