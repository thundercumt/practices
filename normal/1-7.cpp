#include <iostream>
#include <cctype>

using namespace std;

const int N = 8;

char g[N+2][N+2] = {0};

bool empty_board() {
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      if (g[i][j] != '.') {
        return false;
      }
    }
  }
  return true;
}

bool ext_contains(int i, int j, int stepx, int stepy, char space, char t) {
  int x, y;
  for (x=i+stepx, y=j+stepy; x>=1 && x<=N && y>=1 && y<=N && g[x][y]==space; x+=stepx, y+=stepy); 

  if (x>=1 && x<=N && y>=1 && y<=N && g[x][y] == t) return true;
  return false;
}

int king_in_danger() {
  int rb = 0, rw = 0;
  int i, j, m;
  char c, t;

  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      c = g[i][j];
      if (c == '.') continue;

      if (islower(c) && !rw) {
        t = 'K';
        switch(c){
        case 'p':
          if (g[i+1][j-1] == t || g[i+1][j+1] == t) rw = 1;
          break;
        case 'n':
          if (i-2>=1 && (g[i-2][j-1] == t || g[i-2][j+1] == t)) rw = 1;
          if (i+2<=N && (g[i+2][j-1] == t || g[i+2][j+1] == t)) rw = 1;
          if (j-2>=1 && (g[i-1][j-2] == t || g[i+1][j-2] == t)) rw = 1;
          if (j+2<=N && (g[i-1][j+2] == t || g[i+1][j+2] == t)) rw = 1;
          break;
        case 'r':
          if (ext_contains(i, j, -1, 0, '.', t)) rw = 1;
          if (ext_contains(i, j, 1, 0, '.', t)) rw = 1;
          if (ext_contains(i, j, 0, -1, '.', t)) rw = 1;
          if (ext_contains(i, j, 0, 1, '.', t)) rw = 1;
          break;
        case 'b':
          if (ext_contains(i, j, -1, -1, '.', t)) rw = 1;
          if (ext_contains(i, j, 1, 1, '.', t)) rw = 1;
          if (ext_contains(i, j, -1, 1, '.', t)) rw = 1;
          if (ext_contains(i, j, 1, -1, '.', t)) rw = 1;
          break;
        case 'q':
          if (ext_contains(i, j, -1, 0, '.', t)) rw = 1;
          if (ext_contains(i, j, 1, 0, '.', t)) rw = 1;
          if (ext_contains(i, j, 0, -1, '.', t)) rw = 1;
          if (ext_contains(i, j, 0, 1, '.', t)) rw = 1;
          if (ext_contains(i, j, -1, -1, '.', t)) rw = 1;
          if (ext_contains(i, j, 1, 1, '.', t)) rw = 1;
          if (ext_contains(i, j, -1, 1, '.', t)) rw = 1;
          if (ext_contains(i, j, 1, -1, '.', t)) rw = 1;
          break;
        case 'k':
          if (g[i-1][j-1] == t) rw = 1;
          if (g[i-1][j] == t) rw = 1;
          if (g[i-1][j+1] == t) rw = 1;
          if (g[i][j-1] == t) rw = 1;
          if (g[i][j+1] == t) rw = 1;
          if (g[i+1][j-1] == t) rw = 1;
          if (g[i+1][j] == t) rw = 1;
          if (g[i+1][j+1] == t) rw = 1;
          break;
        }
      }
      else if (isupper(c) && !rb) {
        t = 'k';
        switch(c){
        case 'P':
          if (g[i-1][j-1] == t || g[i-1][j+1] == t) rb = 1;
          break;
        case 'N':
          if (i-2>=1 && (g[i-2][j-1] == t || g[i-2][j+1] == t)) rb = 1;
          if (i+2<=N && (g[i+2][j-1] == t || g[i+2][j+1] == t)) rb = 1;
          if (j-2>=1 && (g[i-1][j-2] == t || g[i+1][j-2] == t)) rb = 1;
          if (j+2<=N && (g[i-1][j+2] == t || g[i+1][j+2] == t)) rb = 1;
          break;
        case 'R':
          if (ext_contains(i, j, -1, 0, '.', t)) rb = 1;
          if (ext_contains(i, j, 1, 0, '.', t)) rb = 1;
          if (ext_contains(i, j, 0, -1, '.', t)) rb = 1;
          if (ext_contains(i, j, 0, 1, '.', t)) rb = 1;
          break;
        case 'B':
          if (ext_contains(i, j, -1, -1, '.', t)) rb = 1;
          if (ext_contains(i, j, 1, 1, '.', t)) rb = 1;
          if (ext_contains(i, j, -1, 1, '.', t)) rb = 1;
          if (ext_contains(i, j, 1, -1, '.', t)) rb = 1;
          break;
        case 'Q':
          if (ext_contains(i, j, -1, 0, '.', t)) rb = 1;
          if (ext_contains(i, j, 1, 0, '.', t)) rb = 1;
          if (ext_contains(i, j, 0, -1, '.', t)) rb = 1;
          if (ext_contains(i, j, 0, 1, '.', t)) rb = 1;
          if (ext_contains(i, j, -1, -1, '.', t)) rb = 1;
          if (ext_contains(i, j, 1, 1, '.', t)) rb = 1;
          if (ext_contains(i, j, -1, 1, '.', t)) rb = 1;
          if (ext_contains(i, j, 1, -1, '.', t)) rb = 1;
          break;
        case 'K':
          if (g[i-1][j-1] == t) rb = 1;
          if (g[i-1][j] == t) rb = 1;
          if (g[i-1][j+1] == t) rb = 1;
          if (g[i][j-1] == t) rb = 1;
          if (g[i][j+1] == t) rb = 1;
          if (g[i+1][j-1] == t) rb = 1;
          if (g[i+1][j] == t) rb = 1;
          if (g[i+1][j+1] == t) rb = 1;
          break;
        }
      }
    }
  }

  if (rw==1 && rb == 0)
    return -1;
  else if (rw==0 && rb==1)
    return 1;
  else if (rw==0 && rb==0)
    return 0;
  else
    return 2;
}

int main() {
  int i, j, n, r;

  n = 0;
  while (true) {
    ++n;

    for (i=1; i<=N; i++) {
      for (j=1; j<=N; j++) {
        cin >> g[i][j];
      }
    }

    if (empty_board()) break;


    cout << "Game #" << n << ": ";
    r = king_in_danger();

    switch(r) {
    case 0:
      cout << "no king is in check.";
      break;
    case 1:
      cout << "black king is in check.";
      break;
    case -1:
      cout << "white king is in check.";
      break;      
    }
    cout << '\n';
  }

  
}
