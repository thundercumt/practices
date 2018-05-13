#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

string dict[] = {
  "ad",
  "as",
  "ah",
  "act",
  "ash",
  "add",
  "away",
  "area",
  "dog",
  "desk",
  "game",
  "guy",
  "guess",
  "tank",
  "task",
  "took",
  "twin",
  "stay",
  "seven",
  "sun",
  "son",
  "sluggish",
  "slam",
  "dwell",
  "meeting",
  "shrink",
  "jelly",
  "fish",
  "flower",
  "five",
  "hawk",
  "hatred",
  "hazzard",
  "zoo",
  "haddop",
  "hive",
  "keeper",
  "java",
  "python",
  "ruby",
  "swift"
};

template<typename T>
inline void exchange(T &a, T &b) {
  T t = a;
  a = b;
  b = t;
}

string crypt(const string word, char (alpha)[26]) {
  string s;
  for (string::const_iterator it=word.begin(); it!=word.end(); ++it) {
    s.push_back(alpha[*it-'a']);
  }
  return s;
}

int main() {
  size_t n = sizeof(dict) / sizeof(dict[0]);
  
  vector<string> v;

  cout << n << endl;
  for (int i=0; i<n; ++i) {
    cout << dict[i] << endl;
  }
  cout << endl;

  for (int i=0; i<10; i++) {
    v.clear();
    int n_words = rand() % n % 6;

    char alpha[26];
    for (int j=0; j<26; ++j) alpha[j] = 'a' + j;

    for (int j=0; j<26; ++j) {
      int r = rand() % 26;
      exchange(alpha[j], alpha[r]);
    }

    //for (int j=0; j<26; ++j) cout << alpha[j] << " ";

    for (int j=0; j<n_words; ++j) {
      int r = rand() % n;
      if (j) cout << ' ';
      //cout << crypt(dict[r], alpha);
      cout << dict[r] << ' ';
    }
    cout << endl;
  }
  
}
