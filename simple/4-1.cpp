#include <iostream>
#include <string>

using namespace std;


int main() {
  string s;
  int i, chksum;

  while (true ) {
    getline(cin, s);
    if (s == "#") break;

    chksum = 0;
    for (i=0; i<s.size(); i++) {
      chksum += s[i]!=' ' ? (i+1)*(s[i]-'A'+1) : 0;
    }
    cout << chksum << endl;
  }
}
