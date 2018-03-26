#include <iostream>
#include <iomanip>

#include <cmath>

using namespace std;

int main() {
  double r, q;
  int n;

  cout << fixed << setprecision(3);
  //@loop_invariant 0 < q && q < 2 && n > 0 && n <= 20
  while(cin >> n >> q) {
    if (q == 1) {
      r = n + 1;
    } else {
      r = ::pow(q, n+1);
      r = (r - 1) / (q - 1);
    }
    cout << r << endl;
  }

}
