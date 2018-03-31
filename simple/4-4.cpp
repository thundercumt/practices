#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;


int main() {
  char buf[N];
  int n, i, j, l, c;
  char lc;

  cin >> n;
  cin.getline(buf, N);//skip the trailing \n
  for (i=0; i<n; i++) {
    memset(buf, 0, N);
    cin.getline(buf, N);
    l = strlen(buf);

    lc = '-';//some character outside of alphabet
    c = 0;
    j = 0;

    while (j<l) {
      lc = buf[j];
      c = 1;

      //@loop_invariant buf[j..j+c) == lc and [j..j+c) < l
      while (j+c < l && buf[j+c]==lc) c++;

      if (c>1) cout << c;
      cout << lc;
      j += c;
    }

    cout << endl;
  }

}
