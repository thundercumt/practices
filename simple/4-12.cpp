#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverse_s(string& s) {
  string::iterator f, t;

  for (f = s.begin(), t=f+1;
       f < s.end();) {
    while(t != s.end() && *t != ' ') t++;

    reverse(f, t);

    f = t + 1;
    t = f + 1;
  }
}

int main() {
  int n, i, m, j, k;
  string s;

  cin >> n;
  getline(cin, s); //skip the trailing \n

  for (i=0; i<n; i++) {
    getline(cin, s); // skip the blank line

    cin >> m;
    getline(cin, s); //skip the trailing \n

    if (i > 0) cout << endl;
    for (j=0; j<m; j++) {
      getline(cin, s);

      reverse_s(s);

      cout << s << endl;
    }
  }

}
