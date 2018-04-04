#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> m;

int main() {
  string s, ew, mw;
  size_t p;

  while (true) {
    getline(cin, s);
    if (s == "") break;

    p = s.find(' ');
    ew = s.substr(0, p);
    mw = s.substr(p + 1);
    m.insert(pair<string, string>(mw, ew));
  }

  while (cin >> s) {
    if (m.count(s) > 0)
      cout << m[s] << endl;
    else
      cout << "eh" << endl;
  }
}
