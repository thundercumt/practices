#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, i, m, j;
  string s1, s2, t;

  cin >> n;

  for (i=0; i<n; i++) {

    cin >> m;
    s1.clear();
    for (j=0; j<m; j++) {
      cin >> t;
      s1.push_back(t[0]);
    }

    cin >> m;
    s2.clear();
    for (j=0; j<m; j++) {
      cin >> t;
      s2.push_back(t[0]);
    }

    if (s1 == s2)
      cout << "SAME" << endl;
    else
      cout << "DIFFERENT" << endl;
    
  }

}
