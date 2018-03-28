#include <iostream>

using namespace std;

const int N = 99999;

char primes[N + 1] = {0};

void init_primes() {
  int i, j;
  for (i=2; i<=N; i++) {
    primes[i] = 1;
  }

  for(i=2; i<=N; i++) {
    if (primes[i]) {
      j = i << 2;
      while(j <= N) {
        primes[j] = 0;
        j <<= 2;
      }
    }
  }
}

//@requires n > 0 && n < 2^32
bool symmetric(int n) {
  if (n < 0 && n < 10) {
    return true;
  }
  if (n < 100) {
    return (n / 10) == (n % 10);
  }
  if (n < 1000) {
    return (n / 100) == (n % 10);
  }
  if (n < 10000) {
    return (n / 1000) == (n % 10) && ((n / 100) % 10) == ((n / 10) % 10);
  }
  if (n <= N) {
    return (n / 10000) == (n % 10) && ((n / 1000) % 10) == ((n / 10) % 10);
  }
  return false;
}

inline bool in_range(int n) {
  return 0 < n && n <= N;
}

int main() {
  int n, i;
  init_primes();

  while(cin >> n) {
    if (in_range(n) && primes[n] && symmetric(n))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

