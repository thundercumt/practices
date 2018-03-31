#include <iostream>
#include <string>

using namespace std;

unsigned int root(unsigned int i) {
  unsigned int s=i, r;

  while (s >= 10) {
    r = 0;
    while (s) {
      r += s % 10;
      s /= 10;
    }

    s = r;
  }
  return s;
}

int main() {
  unsigned int n;
  string s;
  string::iterator it;

  while (cin >> s) {
    n = 0;
    for (it=s.begin(); it!=s.end(); it++) {
      n += (*it) - '0';
    }
    
    if (!n) break;
    cout << root(n) << endl;
  }

  return 0;
}
