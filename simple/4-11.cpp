#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int n, i;
  string s;

  cin >> n;
  getline(cin, s); //skip trailing \n
  for (i=0; i<n; i++) {
    getline(cin, s);
    reverse(s.begin(), s.end());
    cout << s << endl;
  }

}
