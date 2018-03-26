#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int n, s, i, t;

  cout << fixed << setprecision(3);

  while(cin >> n) {
    s = 0;
    for(i=0; i<n; i++) {
      cin >> t;
      s += t;
    }
    cout << ((double) s) / n << endl;
  }

  return 0;
}
