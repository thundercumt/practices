#include <iostream>
#include <set>

using namespace std;

int main() {

  int n, c;
  set<int> s;
  set<int>::iterator it;

  c = 0;
  while (true) {

    cin >> n;

    if (n == -1) break;

    if (n != 0) s.insert(n);

    if (n == 0) {

      for (it=s.begin(); it!=s.end(); it++) {
        if (s.count(*it * 2)) c++; 
      }

      cout << c << endl;

      s.clear();
      c = 0;
    }

  }

  return 0;
  
}
