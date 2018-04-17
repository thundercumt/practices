#include <iostream>

using namespace std;

int main() {
  int g[10][10];
  int n;

  int i,j,s,c;

  while (true) {
  outer:
    cin >> n;

    if (!n) break;

    for (i=0; i<n; i++) {
      for (j=0; j<n; j++)
        cin >> g[i][j];
    }

    for (i=0; i<n*n; i++) {
      c = g[i/n][i%n];
      for (j=i+1; j<n*n; j++)
        if (g[j/n][j%n] == c) {
          cout << "No" << endl;
          goto outer;
        }
    }

    s = 0;
    for (i=0; i<n; i++) s += g[0][i];

    for (i=1; i<n; i++) {
      c = 0;
      for (j=0; j<n; j++) c += g[i][j];

      if (c!=s) {
        cout << "No" << endl;
        goto outer;
      }
    }

    for (i=0; i<n; i++) {
      c = 0;
      for (j=0; j<n; j++) c += g[j][i];

      if (c!=s) {
        cout << "No" << endl;
        goto outer;
      }
    }

    c = 0;
    for (i=0; i<n; i++) c += g[i][i];

    if (c!=s) {
      cout << "No" << endl;
      goto outer;
    }

    c = 0;
    for (i=0; i<n; i++) c += g[i][n-i-1];

    if (c!=s) {
      cout << "No" << endl;
      goto outer;
    }

    cout << "Yes" << endl;

  }

  return 0;

}
