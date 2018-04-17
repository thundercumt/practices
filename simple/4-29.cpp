#include <iostream>
#include <vector>

using namespace std;

const int N = 1000000;

char g[N+1] = {0};
vector<int> v;

int main() {
  int n, i, j;
  int c;

  for (i=2; i<=N; i++) {
    if (!g[i]) {
      v.push_back(i);
      j = i + i;

      while(j<=N) {
        g[j] = 1;
        j += i;
      }
    }
  }

  for (i=0; i<v.size(); i++) {
    for (j=i; j<v.size(); j++) {
      c = v[i] * v[j];
      if (c>0 && c<=N) {
        g[c] = 2;
      }
      else {
        break;
      }
    }
  }

  
  while (cin >> n) {
    if (g[n] == 2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;

}
