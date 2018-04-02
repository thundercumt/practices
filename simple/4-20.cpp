#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 100;

int mn2ed(char c) {
  if ('0' <= c && c <= '9') return c - '0';
  if ('a' <= c && c <= 'j') return c - 'a' + 10;
  return 0xCCCCCCCC;
}

char ed2mn(int i) {
  if (0 <= i && i <= 9) return '0' + i;
  if (10 <=i && i <=19) return 'a' + i - 10;
  return 'x';
}

inline char digit(const string& s, int i) {
  return i >= s.size() ? '0' : s[i];
}

int main() {
  string s1, s2, s;
  int i, c, t, n;

  while (cin >> s1 >> s2) {
    s.clear();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    c=0;
    n = s1.size() > s2.size() ? s1.size() : s2.size();
    for (i=0; i<n; i++) {
      t = mn2ed(digit(s1,i)) + mn2ed(digit(s2,i)) + c;
      s.push_back(ed2mn(t % 20));
      c = t / 20;
    }

    if (c > 0) s.push_back(ed2mn(c));
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
}

