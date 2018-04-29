#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

template<typename T, T NA,  size_t R, size_t C>
class Editor {
public:
  void init(size_t m, size_t n) {
    _m = m;
    _n = n;
    for (size_t i=1; i<=m; i++) {
      for (size_t j=1; j<=n; j++) {
        v[i][j] = NA;
      }
    }
  }

  void clear() {
    for (size_t i=1; i<=_m; i++) {
      for (size_t j=1; j<=_n; j++) {
        v[i][j] = NA;
      }
    }
  }

  void point(size_t x, size_t y, T c) {
    v[x][y] = c;
  }

  void vline(size_t x1, size_t x2, size_t y, T c) {
    for (size_t i=x1; i<=x2; i++)
      v[i][y] = c;
  }

  void hline(size_t x, size_t y1, size_t y2, T c) {
    for (size_t i=y1; i<=y2; i++)
      v[x][i] = c;
  }

  void rect(size_t x1, size_t y1, size_t x2, size_t y2, T c) {
    for (size_t i=x1; i<=x2; i++) {
      for (size_t j=y1; j<=y2; j++)
        v[i][j] = c;
    }
  }

  void fill(size_t x, size_t y, const T c) {
    T oc = v[x][y];
    if (c == oc) return;
    if (x<1 || x>_m || y<1 || y>_m) return;
    
    char visited[R+1][C+1] = {{0}};
    fill(x, y, c, oc, visited);
  }

  void save(const string& name) {
    cout << name << '\n';
    for (size_t i=1; i<=_m; i++) {
      for (size_t j=1; j<=_n; j++) {
        cout << v[i][j];
      }
      cout << '\n';
    }
  }
  
private:
  void fill(size_t x, size_t y, const T c, const T oc, char(&visited)[R+1][C+1]) {
    visited[x][y] = 1;
    
    if (v[x][y] != oc) return;

    v[x][y] = c;

    if (x>1 && !visited[x-1][y]) fill(x-1, y, c, oc, visited);
    if (y<_n && !visited[x][y+1]) fill(x, y+1, c, oc, visited);
    if (x<_m && !visited[x+1][y]) fill(x+1, y, c, oc, visited);
    if (y>1 && !visited[x][y-1]) fill(x, y-1, c, oc, visited);
  }
  
  T v[R+1][C+1];
  size_t _m, _n;
};

int main() {
  Editor<char, '0', 250, 250> ed;

  string s;
  size_t a1, a2, a3, a4;
  char c;

  while (cin >> c) {

    switch (c) {
    case 'I':
      cin >> a1 >> a2;
      ed.init(a2, a1);
      break;
    case 'C':
      ed.clear();
      break;
    case 'L':
      cin >> a1 >> a2 >> c;
      ed.point(a2, a1, c);
      break;
    case 'V':
      cin >> a1 >> a2 >> a3 >> c;
      ed.vline(a2, a3, a1, c);
      break;
    case 'H':
      cin >> a1 >> a2 >> a3 >> c;
      ed.hline(a3, a1, a2, c);
      break;
    case 'K':
      cin >> a1 >> a2 >> a3 >> a4 >> c;
      ed.rect(a2, a1, a4, a3, c);
      break;
    case 'F':
      cin >> a1 >> a2 >> c;
      ed.fill(a2, a1, c);
      break;
    case 'S':
      cin >> s;
      ed.save(s);
      break;
    case 'X':
      goto done;
      break;
    default:
      getline(cin, s);
    }
  }

  done:
  return 0;
  
}
