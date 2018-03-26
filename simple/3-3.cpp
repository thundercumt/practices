#include <iostream>

using namespace std;

const int MAX_N = 12;
static int FACTORIAL[MAX_N + 1] = {1, 1, 0};

int factorial(int n) {
  if (n == 0) return 1;
  if (n == 1) return 1;

  if (n > MAX_N) exit(-1);

  int t = n * factorial(n-1);
  if (FACTORIAL[n] == 0) FACTORIAL[n] = t;
  return t;
}

int solution1() {
  int i, n, t;

  while(cin >> n) {
    t = 0;

    for(i=1; i<=n; i++) {
      t += factorial(i); 
    }

    cout << t << endl;
  }

  return 0;
}


int solution2() {
  int i, n, f, r;

  //@loop_invariant: n >= 1 && n <= 12 (guaranteed by input)
  while( cin >> n) {
    r = 1;
    f = 1;

    //@loop_invariant: r == sum(factorial(1~i)), f == factorial(i)
    for (i=2; i<=n; i++) {
      f *= i;
      r += f;
    }

    cout << r << endl;
  }

  return 0;
}

int main() {
  solution2();
}
