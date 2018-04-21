#include <iostream>

using namespace std;

int main() {

  int n, i, v, t, s, l;

  while (true) {

    cin >> n;

    if (n == -1) break;


    s = 0;
    l = 0;
    for (i=0; i<n; i++) {
      cin >> v >> t;
      s += v * (t-l);
      l = t;
    }

    cout << s << " miles" << endl;

  }

}
