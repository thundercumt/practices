#include <iostream>

using namespace std;

const long N = 1000000;

int cv[N] = {0, 1};

int calcv(long n) {
  if (n<N && cv[n]) return cv[n];

  int c;
  if (n%2 == 0) {
    c = calcv(n>>1) + 1;
  }
  else {
    c = calcv(n*3+1) + 1;
  }
  if (n<N) cv[n] = c;

  return c;
}

int main() {

  int i, j, ii, jj, k, c, t, x;

  while (cin >> i >> j) {
    ii = i, jj = j;
    if (i > j) {
      ii = j;
      jj = i;
    }

    c = 0;
    for (k=ii; k<=jj; k++) {
      t = calcv(k);
      if (t>c) x = k;
      c = t > c ? t : c;
    }

    cout << i << " " << j << " " << c << "\n";
  }

}
