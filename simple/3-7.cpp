#include <iostream>

using namespace std;


int gcd(int m, int n) {
  if (n > m) return gcd(n, m);

  if (n == 0) return m;

  int r = m % n;
  return gcd(n, r);
}

//@require 0 < m, n < 100,000 
int lcm(int m, int n) {
  int c = gcd(m, n);
  return m / c * n;
}


int main() {
  int m, n;

  while(cin >> m >> n) {
    cout << lcm(m, n) << endl;
  }
}
