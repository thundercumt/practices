#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;

char g1[N+2][N+2];//mine input
char g2[N+2][N+2];//board status
short g3[N+2][N+2];//count of each cell


int main() {

  int n, i, j;

  while (cin >> n) {
    for (i=1; i<=N; i++) {
      for (j=1; j<=N; j++) {
        g3[i][j] = 0;
      }
    }
    memset(g3, 0, (N+2)*(N+2));

    for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) {
        cin >> g1[i][j];
      }
    }

    for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) {
        cin >> g2[i][j];
      }
    }

    for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) {
        if (g1[i][j] == '*') {
          if (g1[i-1][j-1] == '.') g3[i-1][j-1]++;
          if (g1[i-1][j] == '.') g3[i-1][j]++;
          if (g1[i-1][j+1] == '.') g3[i-1][j+1]++;
          if (g1[i][j-1] == '.') g3[i][j-1]++;
          if (g1[i][j+1] == '.') g3[i][j+1]++;
          if (g1[i+1][j-1] == '.') g3[i+1][j-1]++;
          if (g1[i+1][j] == '.') g3[i+1][j]++;
          if (g1[i+1][j+1] == '.') g3[i+1][j+1]++;
        }
      }
    }

    bool game_over = false;
    for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) {
        if (g2[i][j]=='x' && g1[i][j]=='*') {
          game_over = true;
          goto output;
        }
      }
    }
    
  output:
    for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) {
        //touched cell
        if (g2[i][j]=='x') {
          if (g1[i][j] == '*')
            cout << '*';
          else
            cout << g3[i][j];
        }
        //untouched cell
        else {
          if (game_over && g1[i][j]=='*')
            cout << '*';
          else
            cout << '.';
        }
      }
      cout << "\n";
    }
  }

  return 0;
}
