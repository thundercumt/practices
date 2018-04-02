#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class item {
public:
  item(int i, int j):_i(i),_j(j){}
  int i() const { return _i; }
  int j() const { return _j; }

private:
  int _i;
  int _j;
};

bool item_less(const item& a, const item& b) {
  return a.i() != b.i() ? a.i() < b.i() : a.j() < b.j();
}

int measure(const string& s) {
  int i, j, c;

  c = 0;
  for (i=0; i<s.size(); i++) {
    for (j=i+1; j<s.size(); j++)
      if (s[i] > s[j]) c++;
  }

  return c;
}

int main() {
  vector<string> v;
  vector<item> r;
  int n, p, q, i, j;
  string s;
  vector<item>::iterator it;

  cin >> n;

  for (i=0; i<n; i++) {
    cin >> p >> q;

    v.clear();
    r.clear();

    if (i) cout << endl;

    for (j=0; j<q; j++) {
      cin >> s;
      v.push_back(s);
      r.push_back(item(measure(s), j));
    }

    sort(r.begin(), r.end(), item_less);

    for (it=r.begin(); it!=r.end(); it++) {
      cout << v[it->j()] << endl;
    }
  }
}
