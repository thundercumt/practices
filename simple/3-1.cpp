#include <iostream>

using namespace std;

const int MAX=10000;
const int MIN=1;

int main() {
  int i;
  while(cin >> i) {
    if (i < MIN || i > MAX) {
      cout << "out of range:" << i << endl;
      return -1;
    }

    cout << i * i << endl;
  }
}
