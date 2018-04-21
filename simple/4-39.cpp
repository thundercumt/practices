#include <iostream>

using namespace std;

int main() {

  int n, c, x, y;

  while (true) {

    cin >> n;

    if (!n) break;

    c = 0;

    while (n > 1) {
      x = n / 3;
      y = n % 3;

      if (x>0) {
        c += x;
      }
      else {
        c += 1;
        y = 1;
      }
      n = x + y;
    }

    cout << c << endl;

  }

}
