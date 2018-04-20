#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline char get_num(const string& s, int i) {
  return i >= s.size() ? 0 : s[i] - '0';
}

void add_to_num(string& a, const string& b) {
  int i, t, c;

  string s;

  c = 0;
  for (i=0; i<a.size() || i<b.size() || c>0; i++) {

    t = get_num(a, i) + get_num(b, i) + c;
    if (t > 9) {
      c = 1;
      s.push_back(t - 10 + '0');
    }
    else {
      c = 0;
      s.push_back(t + '0');
    }
  }

  a = s;
}

void copy_numbers_to(const string& a, string & b) {
  for (string::const_iterator it = a.begin();
       it != a.end();
       it++) {

    switch(*it) {
    case '$': case '.': case ',':
      continue;
    default:
      b.push_back(*it);
    }
  }
}

int main() {

  string s1, s2, s;

  int n, c, i;

  while (true) {

    cin >> n;

    if (!n) break;

    s.clear();

    cin >> s1;
    reverse(s1.begin(), s1.end());
    copy_numbers_to(s1, s);

    for (i=1; i<n; i++) {

      s1.clear();
      cin >> s2;
      reverse(s2.begin(), s2.end());
      copy_numbers_to(s2, s1);

      add_to_num(s, s1);
    }

    s1.clear();
    string::iterator it = s.begin();

    s1.push_back(*it++);
    s1.push_back(*it++);
    s1.push_back('.');

    for (c=0; it!=s.end(); it++, c++) {
      if (c==3) {
        s1.push_back(',');
        c = 0;
      }
      s1.push_back(*it);
    }

    s1.push_back('$');

    reverse(s1.begin(), s1.end());
    cout << s1 << endl;
  }

  return 0;

}
