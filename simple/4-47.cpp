#include <iostream>

using namespace std;

const int N = 1000000;

char fib[N];

int main() {
  
  int i;

  fib[0] = 7 % 3;
  fib[1] = 11 % 3;

  for (i=2; i<N; i++) {
    fib[i] = (fib[i-1] + fib[i-2]) % 3;
  }

  while (cin >> i) {
    if (!fib[i])
      cout << "yes";
    else
      cout << "no";

    cout << "\n";
  }

}
