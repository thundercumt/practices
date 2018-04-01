#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  int a, b, c;
  int i, j;

  i = 1;
  while (true) {
    cin >> a >> b >> c;

    if (!a && !b && !c) break;

    cout << "Triangle #" << i << endl;
    if (a == -1 && c > b) {
      cout << fixed << setprecision(3) << sqrt(c*c - b*b) << endl;
    }
    else if (b == -1 && c > a) {
      cout << fixed << setprecision(3) << sqrt(c*c - a*a) << endl;
    }
    else if (c == -1) {
      cout << fixed << setprecision(3) << sqrt(a*a + b*b) << endl;
    }
    else {
      cout << "Impossible." << endl;
    }
    cout << endl;
    
    i++;
  }
}
