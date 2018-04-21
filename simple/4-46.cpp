#include <iostream>
#include <string>

using namespace std;

const string decoder = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main() {
  string s;
  int i, n;

  while (true) {
    getline(cin, s);

    if ("START" == s) continue;
    if ("END" == s) continue;

    if ("ENDOFINPUT" == s) break;

    n = s.size();
    for (i=0; i<n; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] = decoder[s[i] - 'A'];
      }
    }

    cout << s << "\n";
  }

  return 0;

}
