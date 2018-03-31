#include <iostream>

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

  while (cin >> n) {
    if (!n) break;
    cout << root(n) << endl;
  }

  return 0;
}
