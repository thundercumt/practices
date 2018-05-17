#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

enum { N = 26, NW = 16 };

map<string, int> dict;
map<string, set<string> > dict_by_pat;
set<string> puzzle;

//make sure 1-1 mapping
char encoder[N];
char decoder[N];

static int do_crypt(const string& sent, set<string>::iterator begin, set<string>::iterator end);


void crypt(const string& sent) {
  puzzle.clear();

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

  //cout << "\n" << sent << endl;

  memset(encoder, 0, N);
  memset(decoder, 0, N);

  for(map<string, int>::iterator dict_beg=dict.begin(); dict_beg!=dict.end(); ++dict_beg) {
    assert(dict_beg->second == 0);
  }
  
  set<string>::iterator beg_puzzle = puzzle.begin();
  set<string>::iterator end_puzzle = puzzle.end();

  if (!do_crypt(sent, beg_puzzle, end_puzzle)) {
    for (int i=0; i<sent.size(); ++i) {
      if (sent[i] != ' ') cout << '*';
      else cout << sent[i];
    }
    cout << '\n';
  }

  //cout << '\n';//delete me after debug
}

string word_pattern(const string& w) {
  string s;
  char alphabet[N] = {0};
  int cnt = 0;
  char t;
  for (int i=0; i<w.size(); ++i) {
    t = w[i];
    t -= 'a';
    if (alphabet[t] == 0) {
      alphabet[t] = ++cnt;
    }
    s.push_back(alphabet[t]);
  }
  return s;
}


void guess_word_mapping(const string& word, vector<string>& v) {
  size_t sz = word.size();
  string pat_word = word_pattern(word);
  
  set<string>& cand = dict_by_pat[pat_word];

  for (set<string>::iterator it=cand.begin(); it!=cand.end(); ++it) {

    // bool conflict = false;
    // for (int i=0; i<word.size(); ++i) {
    //   char e = (*it)[i];
    //   char d = word[i];
    //   if (encoder[e]!=0 && decoder[d]!=0 && (encoder[e]!=d || decoder[d]!=e)) {
    //     conflict = true;
    //     break;
    //   }
    // }
    
    if (!dict[*it]) v.push_back(*it);
  }
}


int do_crypt(const string& sent, set<string>::iterator begin, set<string>::iterator end) {
  if (begin == end) {
    for (int i=0; i<sent.size(); i++) {
      if (sent[i] != ' ') cout << decoder[sent[i]-'a'];
      else cout << ' ';
    }
    cout << '\n';
    return 1;
  }
  

  set<string>::iterator begin_next(begin);
  ++begin_next;

  const string &w = *begin;
  string guess;
  vector<string> cand;
  guess_word_mapping(w, cand);

  //cout << cand.size() << " candidates for " << w << endl;
  
  if (cand.size() == 0) {
    //cout << "failed because no candidate\n";
    return 0;
  }

  vector<char> alpha_q;
  
  for (int i=0; i<cand.size(); ++i) {
    guess = cand[i];
    assert(guess.size() == w.size());

    //cout << "really trying: " << w << ": " << guess << endl;
    
    for (int j=0; j<guess.size(); ++j) {
      //cout << j << " " << decoder[w[j]-'a'] << " " << encoder[guess[j]-'a'] << endl;
      
      if (decoder[w[j]-'a'] == guess[j] && encoder[guess[j]-'a'] == w[j]) continue;

      else if (decoder[w[j]-'a'] == 0 && encoder[guess[j]-'a']==0) {
        alpha_q.push_back(w[j]);
        decoder[w[j]-'a'] = guess[j];
        encoder[guess[j]-'a'] = w[j];
      }
      
      else {
        //conflict with previously specified cypher
        goto next_candidate;
      }
    }

    
    if (!dict[guess]) {
      dict[guess] = 1;
      if (do_crypt(sent, begin_next, end)) {
        dict[guess] = 0;
        return 1;
      }
      dict[guess] = 0;
    }
    else {
      if (do_crypt(sent, begin_next, end)) return 1;
    }
    

  next_candidate:
    for (int k=0; k<alpha_q.size(); ++k) {
      encoder[decoder[alpha_q[k]-'a']-'a'] = 0;
      decoder[alpha_q[k]-'a'] = 0;
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
    dict_by_pat[word_pattern(s)].insert(s);
  }
  getline(cin, s);//trailing \n

  while (getline(cin, s)) {
    crypt(s);
  }

  return 0;
}
