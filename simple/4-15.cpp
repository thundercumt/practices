#include <iostream>

using namespace std;

const int N = 100;

template<typename T, int N>
void init_color(T (&p)[N][N], int n, int m) {
  int i, j;

  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) {
      cin >> p[i][j];
    }
  }
}

int main() {
  int n, m, i, p, q;
  int r[N][N], g[N][N], b[N][N];

  i = 1;
  while (cin >> n >> m) {
    if (!n && !m) break;

    init_color(r, n, m);
    init_color(g, n, m);
    init_color(b, n, m);

    cout << "Case " << i << ":" << endl;
    for (p=0; p<n; p++) {
      for (q=0; q<m; q++) {
        if (q) cout << ",";
        cout << (r[p][q] + g[p][q] + b[p][q])/3;
      }
      cout << endl;
    }
    i++;
  }    
}
