#include <iostream>
#include <string>
#include <algorithm>

#include <cstdio>
#include <cstring>

const int N = 1001;

char a[N] = {0};
char b[N] = {0};
char c[N] = {0};

int main() {
  int i, j, k, la, lb;

  while (gets(a) && gets(b)) {
    la = strlen(a); lb = strlen(b);
    
    std::sort(a, a+la);
    std::sort(b, b+lb);
    memset(c, 0, N);

    for(i=0, j=0, k=0; i<la && j<lb; ) {
      if (a[i] < b[j]) {
        ++i;
      }
      else if (a[i] > b[j]) {
        ++j;
      }
      else {
        c[k++] = a[i];
        ++i;
        ++j;
      }
    }

    printf("%s\n", c);
  }
}
