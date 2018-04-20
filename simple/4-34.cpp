#include <iostream>
#include <string>

using namespace std;

int main() {

  const int quar = 25, dim = 10, nick = 5, pen = 1;

  int n, i, c;

  int q, d, nc, p;

  cin >> n;

  for (int i=1; i<=n; i++) {

    cin >> c;

    q = c / quar;
    c = c % quar;

    d = c / dim;
    c = c % dim;

    nc = c / nick;
    c = c % nick;

    p = c / pen;

    cout << i << " " << q << " " << "QUARTER(S), ";
    cout << d << " DIME(S), " << nc << " NICKEL(S), " << p << " PENNY(S)" << endl;
    
  }

  return 0;
}
