#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 10000;


int main() {
  vector<int> v;
  int n, i, j, r, s;

  for(i=2; i<N; i++) {

    s = 1; //1 is a factor for all natual numbers
    r = sqrt(i);

    for(j=2; j<=r; j++) {
      if (i % j == 0) {
        s += j;
        s += (i / j);
      }
    }

    if (s == i) v.push_back(i);
  }

  while(cin >> n) {
    cout << n << ":";

    vector<int>::iterator it = v.begin();
    while(it != v.end() && *it <= n) {
      cout << " " << *it;
      it++;
    }

    cout << endl;
  }

}

