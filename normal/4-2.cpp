#include <cstdio>
#include <cstdlib>
#include <cstring>

const int PILE = 31;

const int MAX_BUF = 120;

char * gets_s(char *a) {
  char *r = fgets(a, MAX_BUF, stdin);

  if (r) {
    a[strlen(a) - 1] = 0;
  }

  return r;
}


int main() {
  char buf[MAX_BUF];
  int flapjack[PILE];
  int count;
  char *space, *p, *end;

  int find_inversion(int*, int);
  void flip(int*, int); 

  int w, idx, flip_count;
  
  while (gets_s(buf)) {
    printf("%s\n", buf);
    
    count = 0;
    p = buf;
    end = p + strlen(buf);
    while(p < end && (space=strchr(p, ' '))) {
      *space = 0;
      flapjack[count++] = atoi(p);
      p = space+1;
    }
    if (p < end) flapjack[count++] = atoi(p);

    w = count - 1;
    flip_count = 0;

    while(w >= 0) {
      idx = find_inversion(flapjack, w);
      if (idx == w) {
        w--;
        continue;
      }

      if (idx != 0) {
        if (flip_count) printf(" ");
        printf("%d", count - idx);
        flip(flapjack, idx);
        flip_count++;
      }

      if (flip_count) printf(" ");
      printf("%d", count - w);
      flip(flapjack, w);
      flip_count++;

      w--;
    }
    
    if (flip_count) printf(" ");
    printf("%d\n", 0);
  }

}


int find_inversion(int* buf, int bottom) {
  int idx = bottom;
  for (int i=bottom-1; i>=0; --i) {
    if (buf[i] > buf[idx]) {
      idx = i;
    }
  }

  //printf("find_inversion(buf, %d) => %d\n", bottom, idx);
  return idx;
}


void flip(int* buf, int bottom) {
  int t;
  for (int i=0, j=bottom; i<j; ++i, --j) {
    t = buf[i];
    buf[i] = buf[j];
    buf[j] = t;
  }
}
