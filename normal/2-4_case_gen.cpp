#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

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
  "hadoop",
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

int main(int argc, const char** argv) {
  if (argc != 2) cout << "usage: 2-4.gen <text|code>" << endl;
  bool text = !strcmp("text", argv[1]);
  
  size_t n = sizeof(dict) / sizeof(dict[0]);
  cout << n << endl;//num o dictionary
  
  vector<string> v;

  for (int i=0; i<n; ++i) {
    cout << dict[i] << endl;
  }

  for (int i=0; i<30; i++) {
    v.clear();
    int n_words = rand() % n;

    if (!n_words) {
      n--;
      continue;
    }

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
      if (!text) cout << crypt(dict[r], alpha);
      else cout << dict[r] << ' ';
    }
    cout << endl;
  }
  
}
