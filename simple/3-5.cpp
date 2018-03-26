#include <iostream>
#include <vector>

using namespace std;

const int N = 46;

vector<int> v(N+1, 0);

static void init_fib_table() {
  v[1] = 1;
  for(int i=2; i<=N; i++) {
    v[i] = v[i-1] + v[i-2];
  }
}


int main() {
  int n;
  init_fib_table();

  while(cin >> n) {
    cout << v[n] << endl;
  }

}
