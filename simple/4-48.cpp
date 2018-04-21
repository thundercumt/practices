#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

#include <cctype>


using namespace std;

int calc_incidence(const set<string>& keys, const string& s) {
  string t;
  int c = 0;
  int n = s.size();
  
  for (int i=0; i<n; i++) {

    if (isalpha(s[i])) {

      t.push_back(tolower(s[i]));

      for(int j=i+1; j<n && isalpha(s[j]); j++) {
        t.push_back(tolower(s[j]));
      }

      if (keys.count(t)) c++;

      t.clear();
    }
  }

  return c;
}


bool pair_cmp(const pair<string, int>& a, const pair<string, int>& b) {
  return a.second > b.second;
}


int main() {

  set<string> keys;
  map<string, int> exes;

  int nk, ne, i, j, c;
  string s;
  int caseid = 0;

  while (cin >> nk >> ne) {

    caseid++;
    if (caseid > 1) cout << "\n";
    cout << "Excuse Set #" << caseid << "\n";
    
    keys.clear();
    exes.clear();
    
    for (i=0; i<nk; i++) {
      cin >> s;
      keys.insert(s);
    }
    getline(cin, s);//skip the trailing \n

    for (i=0; i<ne; i++) {
      getline(cin, s);

      c = calc_incidence(keys, s);
      exes[s] = c;
    }

    vector< pair<string, int> > v(exes.begin(), exes.end());
    sort(v.begin(), v.end(), pair_cmp);

    c = v[0].second;
    for (i=0; i<v.size(); i++) {
      if (v[i].second == c) cout << v[i].first << "\n";
      else break;
    }
  }

  cout << endl;

}
