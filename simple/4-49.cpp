#include <iostream>

using namespace std;

int main() {

  int i,c;

  while (true) {
    cin >> i;

    if (!i) break;

    c = 0;

    while (!(i&1)) {
      c++;
      i >>= 1;
    }
    cout << (1<<c) << "\n";

  }

}
