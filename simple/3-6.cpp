#include <iostream>

using namespace std;

//@requires m > 0 && n > 0
int gcd(int m, int n) {
  if (m < 0 || n < 0) exit(-1);

  if (n > m) return gcd(n, m);

  if (n == 0) return m;

  int r = m % n;
  return gcd(n, r);
}

int main() {

  int m, n;

  while(cin >> m >> n) {

    cout << gcd(m, n) << endl;
    
  }

}
