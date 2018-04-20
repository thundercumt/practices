#include <iostream>

using namespace std;

int main() {
  int n, c, i, j, t, k;

  cin >> n;

  for (i=0; i<n; i++) {

    cin >> c;

    t = 1;

    for (j=0; j<c; j++) {
      cin >> k;
      t += k;
    }

    t -= c;

    cout << t << endl;

  }
}
