#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const int N = 3000 + 1;

int main() {

  int n, a, b, i, v;
  bitset<N> bs;
  bool check;

  while (cin >> n) {
    //cout << n << endl;
    bs.reset();

    if (n==1) {
      cin >> a;
      cout << "Jolly\n";
      continue;
    }

    check = true;
    cin >> a;
    for (i=1; i<n; i++) {
      cin >> b;
      v = abs(a - b);
      if (v>0 && v<n) {
        bs.set(v);
        a = b;
      }
      else {
        check = false;
        for (int j=i+1; j<n; j++) cin >> b;//read rest numbers in the line
        break;
      }
    }

    if (check && bs.count() == (n-1)) cout << "Jolly\n";
    else cout << "Not jolly\n";
  }
  
}
