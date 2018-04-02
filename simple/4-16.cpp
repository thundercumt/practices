#include <iostream>

using namespace std;

const int N = 10;

static bool is_beautiful(const int (&g)[N][N], int n, int m) {
  int c1, i, j;

  c1 = 1;
  for (i=0; i<n-1; i++) {
    for (j=0; j<m-1; j++) {
      c1 &= g[i][j];
      if (!g[i][j]) {
	if (!g[i][j+1]) return false;//adjacent horizontally mowed
	if (!g[i+1][j]) return false;//adjacent vertically mowed
      }
    }
    c1 &= g[i][j];
    if (!g[i][j] && !g[i+1][j]) return false;
  }

  for (j=0; j<m-1; j++) {
    c1 &= g[i][j];
    if (!g[i][j] && !g[i][j+1]) return false;
  }

  if (c1) return false;

  return true;
}

int main() {
  int n, m, i, j;
  int g[N][N];
  
  while (cin >> n >> m) {
    if (!n && !m) break;

    for (i=0; i<n; i++) {
      for (j=0; j<m; j++) {
	cin >> g[i][j];
      }
    }

    if (is_beautiful(g, n, m)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
