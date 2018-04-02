#include <iostream>

using namespace std;

const int N = 100;

int main() {
  int g[N][N];
  int n, i, j;
  int rc, ri, cc, cj, t;

  while (cin >> n) {
    if (!n) break;
    
    rc = 0;
    for (i=0; i<n; i++) {

      t = 0;
      for (j=0; j<n; j++) {
        cin >> g[i][j];

        t += g[i][j];
      }

      if ((t&1) == 1) {
        rc++;
        ri = i;
      }
    }

    cc = 0;
    for (j=0; j<n; j++) {
      t = 0;
      for (i=0; i<n; i++) {
        t += g[i][j];
      }

      if ((t&1) == 1) {
        cc++;
        cj = j;
      }
    }

    if (!rc && !cc) {
      cout << "OK" << endl;
    }
    else if (rc==1 && cc==1) {
      cout << "Change bit (" << ri+1 << "," << cj+1 << ")" << endl;
    }
    else {
      cout << "Corrupt" << endl;
    }

  }

}
