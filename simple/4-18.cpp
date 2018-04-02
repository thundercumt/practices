#include <iostream>

using namespace std;


int main() {
  int n, a, b, c;

  while (cin >> n) {
    if (n >= 100 && n <=999) {
      a = n % 10;
      b = n / 10 % 10;
      c = n / 100;

      if (a*a*a + b*b*b + c*c*c == n)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    else
      cout << "No" << endl;
  }
  
  return 0;
}
