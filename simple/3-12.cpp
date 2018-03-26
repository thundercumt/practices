#include <iostream>
#include <set>

using namespace std;

int factorial(int n) {
  int r=1, i;

  for(i=2; i<=n; i++)
    r *= i;

  return r;
}


int main() {
  multiset<int> s;
  int n, t, c;
  multiset<int>::iterator it;
  
  t = factorial(12);

  c = 0;
  while (cin >> n) {
    if (t % n == 0) {

      it = s.find(t / n);
      if (it != s.end()) {
        c++;
        s.erase(it);
      } else {
        s.insert(n);
      }
    }
  }

  cout << c << endl;
  return 0;
}
