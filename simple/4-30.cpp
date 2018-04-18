#include <iostream>

using namespace std;

const int a[] = {3, 5, 6, 9, 10, 12, 15};
const int gcd = 15; 

int main() {
  int n;
  int la = sizeof(a) / sizeof(a[0]);

  while (cin >> n) {
    n -= 1; //zero-based
    cout << n / la * gcd + a[n % la] << endl;
  }

  return 0;
}
