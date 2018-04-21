#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_map_pair(const pair<string, int>& a, const pair<string, int>& b) {
  return a.second > b.second;
}


int main() {
  map<string, int> m;

  int n, i;
  string s;

  while (true) {

    cin >> n;

    if (!n) break;

    m.clear();
    for (i=0; i<n; i++) {
      cin >> s;
      m[s]++;
    }

    vector<pair< string, int> > v (m.begin(), m.end());
    sort(v.begin(), v.end(), cmp_map_pair);

    cout << v[0].first << "\n";

  }

}
