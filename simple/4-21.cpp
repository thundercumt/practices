#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class item {
public:
  item(int j, int f):_j(j), _f(f) {}
  int j() const { return _j; }
  int f() const { return _f; }
  double p() const { return ((double)_j) / _f; }
private:
  int _j, _f;
};

bool cheap (const item& a, const item& b) {
  return a.p() > b.p();
}

vector<item> v;

int main() {
  int m, n, i, j, f;
  double t;

  while (cin >> m >> n) {

    if (m==-1 && n==-1) break;
    
    v.clear();
    for (i=0; i<n; i++) {
      cin >> j >> f;
      v.push_back(item(j, f));
    }

    sort(v.begin(), v.end(), cheap);

    t = 0;
    j = 0;
    while (m>0 && j < v.size()) {
      if (v[j].f() <= m) {
        t += v[j].j();
        m -= v[j].f();
      }
      else {
        t += v[j].j() * ((double)m / v[j].f());
        m = 0;
      }

      j++;
    }

    cout << fixed << setprecision(3) << t << endl;
  }

  return 0;

}
