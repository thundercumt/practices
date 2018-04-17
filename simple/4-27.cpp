#include <iostream>
#include <cmath>

using namespace std;

static int prox(double d, int b, int n) {
  double v1, v2;
  v1 = pow((int)d, n);
  v2 = pow((int)d + 1, n);

  return abs(v1 - b) < abs(v2 - b) ? (int)d : (int)d + 1;
}

int main() {
  int b, n;
  double r;

  while (cin >> b >> n) {
    if (!b && !n) break;

    r = pow(b, 1/(double)n);
    //cout << r << " " << prox(r, b, n) << endl;
    cout << prox(r, b, n) << endl;
  }

  return 0;

}
