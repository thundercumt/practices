#include <iostream>
#include <vector>

using namespace std;


int main() {
  vector<int> v;
  vector<int>::iterator it;
  int n, i, t, avg;

  int s=1;
  while (true) {
    cin >> n;

    if (!n) break;

    v.clear();
    avg = 0;
    for (i=0; i<n; i++) {
      cin >> t;
      avg += t;
      v.push_back(t);
    }

    avg /= v.size();
    t = 0;
    for (it=v.begin(); it!=v.end(); it++) {
      if (*it < avg) t += (avg - *it);
    }

    cout << "Set #" << s << endl;
    cout << "The minimum number of moves is " << t << "."  << endl;
    cout << endl;

    s++;
  }
}
