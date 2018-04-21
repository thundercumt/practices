#include <iostream>
#include <cstdio>

using namespace std;

const int N = 500000;

int sums[N+1] = {0};


int main() {

  int n, i, c;
  int j, t, s;

  t = N / 2;
  for (i=2; i<= N; i++) {
    sums[i] = 1;
  }

  for (i=2; i<=t; i++) {
    for (j=i+i; j<=N; j+=i) {
      if (!(j%i)) sums[j] += i;
    }
  }

  cin >> n;

  for (i=0; i<n; i++) {
    scanf("%d", &c);
    printf("%d\n", sums[c]);
  }
}
