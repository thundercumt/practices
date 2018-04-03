#include <iostream>

using namespace std;

int main() {
  int n, c;

  while (true) {
    cin >> n;

    if (!n) break;

    c = 0;
    while (n > 1) {
      if (n & 1) {
	n = (n >> 1) + 1;
      }
      else {
	n = n >> 1;
      }
      c++;
    }
    cout << c << endl;
  }
}
