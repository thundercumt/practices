#include <iostream>

using namespace std;

int main() {

  int n, i, c, s, x;
  int w, k, h, t, a;

  cin >> n;

  for (i=0; i<n; i++) {
    cin >> c;

    cin >> k >> h >> t;

    s = k * 1000 + h * 100 + t*10;

    for (w=9; w>=1; w--) {

      for (a=9; a>=0; a--) {

        x = w * 10000 + s + a;

        if (!(x % c)) {
          cout << w << " " << a << " " << x / c << endl;
          goto done;
        }
      }
    }
    cout << 0 << endl;
  done:
    ;
  }

  return 0;
}
