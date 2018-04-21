#include <iostream>
#include <string>

using namespace std;

inline bool vowel(char c) {
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool good(const string& s) {

  int rpt_mode, rpt_cnt, vowel_cnt;

  int i, n;

  n = s.size();

  vowel_cnt = 0;

  if (vowel(s[0])) {
    rpt_mode = 1;
    vowel_cnt = 1;
  }
  else {
    rpt_mode = 0;
  }
  rpt_cnt = 1;
  
  for (i=1; i<n; i++) {

    if (vowel(s[i])) {
      vowel_cnt++;
      
      if (rpt_mode == 1) {
        rpt_cnt++;

        if (rpt_cnt == 3) return false; //3 consecutive vowels
        else if (s[i-1] == s[i] && s[i] != 'e' && s[i] != 'o') {
          return false; //2 consecutive vowels of same letter
        }
      }
      else {
        rpt_mode = 1;
        rpt_cnt = 1;
      }
    }
    else {
      if (rpt_mode == 1) {
        rpt_mode = 0;
        rpt_cnt = 1;
      }
      else {
        rpt_cnt++;

        if (rpt_cnt == 3) return false; //3 consecutive consonants
        else if (s[i-1] == s[i]) return false; //2 consecutive consonants of same letter 
      }
    }
  }

  if (vowel_cnt == 0) return false;

  return true;
}


int main() {

  string s;

  while (cin >> s) {
    if (s == "end") break;

    if (good(s))
      cout << "<" << s << "> is acceptable.\n";
    else
      cout << "<" << s << "> is not acceptable.\n";
  }

  return 0;
}
