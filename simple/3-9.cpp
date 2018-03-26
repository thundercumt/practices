#include <iostream>
#include <cmath>

using namespace std;

//@require n > 0
int is_prime(int n) {
  int r = sqrt(n);

  for(int i=2; i<=r; i++) {
    if (n%i == 0) {
      return 0;
    }
  }

  return 1;
}


int main() {
  int n;

  while(cin >> n) {

    if (n / 100 > 0 && n / 100 < 10) {
      if (n / 100 == n % 10) {
        if (is_prime(n)) {
          cout << "Yes" << endl;
          continue;
        }
      }
    }
    cout << "No" << endl;
  }
}
