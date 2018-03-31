#include <iostream>
#include <cstring>

using namespace std;

const int N = 80;


int main() {
  char buf[N];
  int i, l;

  while (true) {
    memset(buf, 0, N);
    cin.getline(buf, N);
    l = strlen(buf);

    if (l==1 && buf[0]=='#') break;

    for (i=0; i<l; i++) {
      switch (buf[i]) {
      case ' ':
        cout << "%20";
        break;
      case '!':
        cout << "%21";
        break;
      case '$':
        cout << "%24";
        break;
      case '%':
        cout << "%25";
        break;
      case '(':
        cout << "%28";
        break;
      case ')':
        cout << "%29";
        break;
      case '*':
        cout << "%2a";
        break;
      default:
        cout << buf[i];
      }
    }
    cout << endl;
  }

}
