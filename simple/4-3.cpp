#include <iostream>

using namespace std;


int main() {

  int n, i, j;
  unsigned int k;
  bool first;

  cin >> n;

  for (i=0; i<n; i++) {

    cin >> k;

    j = 0;
    first = true;
    while (k > 0) {
      if (k & 1) {
        if (first) {
          cout << j;
          first = false;
        }
        else {
          cout << " " << j;
        }
      }

      k >>= 1;
      j++;
    }
    cout << endl;
    
  }

}
