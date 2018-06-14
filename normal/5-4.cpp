#include <cstdio>

const int N = 1000;


static int next_cand(int r, int n, int *ones) {
  while(r < n) {
    r *= 10;
    r += 1;
    *ones += 1;
  }
  return r;
}

static void solution(int n) {
  int ones = 1;
  int t;
  int r = 1;

  t = next_cand(r, n, &ones);
  
  while(t) {
    //printf("trying %d\n", t);
    r = t % n;
    if (r==0) break;
    t = next_cand(r, n, &ones);
  }

  printf("%d\n", ones);
}

int main() {
  int n=0;
  
  while(scanf("%d", &n) == 1) {
    solution(n);
  }

  return 0;
}


