#include <cstdio>
#include <cstdlib>

const int MAX_PEOPLE = 1001;
const int MAX_TIME = 101;

typedef struct person {
  int idx;
  int time;
} person;

#define min(a, b) (a<b?a:b)

person input[MAX_PEOPLE];
int n;

int compare_person(const void* a, const void* b) {
  return ((const person*)a)->time - ((const person*)b)->time;
}

int calculate() {
  int left = n;
  int total = 0;

  while (left > 3) {
    int cost1 = input[0].time + input[1].time + input[1].time + input[left-1].time;
    int cost2 = input[0].time + input[left-1].time + input[0].time + input[left-2].time;

    total += min(cost1, cost2);
    left -= 2;
  }

  if (left == 3) {
    total += input[0].time + input[1].time + input[2].time;
  }
  else if (left == 2) {
    total += input[1].time;
  }
  else {
    total += input[0].time;
  }
  
  return total;
}

void solution() {
  int left = n;

  person* ret[2] = {0};

  printf("%d\n", calculate());
  
  while (left > 3) {
    int cost1 = input[0].time + input[1].time + input[1].time + input[left-1].time;
    int cost2 = input[0].time + input[left-1].time + input[0].time + input[left-2].time;

    if (cost1 <= cost2) {
      printf("%d %d\n", input[0].time, input[1].time);
      printf("%d\n", input[0].time);
      printf("%d %d\n", input[left-2].time, input[left-1].time);
      printf("%d\n", input[1].time);
    }
    else {
      printf("%d %d\n", input[0].time, input[left-1].time);
      printf("%d\n", input[0].time);
      printf("%d %d\n", input[0].time, input[left-2].time);
      printf("%d\n", input[0].time);
    }
    left -= 2;
  }

  if (left == 3) {
    printf("%d %d\n", input[0].time, input[left-1].time);
    printf("%d\n", input[0].time);
    printf("%d %d\n", input[0].time, input[left-2].time);  
  }
  else if (left == 2) {
    printf("%d %d\n", input[0].time, input[left-1].time);
  }
  else if (left == 1) {
    printf("%d\n", input[left-1].time);
  }

}


int main() {
  scanf("%d", &n);

  for(int i=0; i<n; ++i) {
    input[i].idx = i;
    scanf("%d", &input[i].time);
  }

  qsort(input, n, sizeof(person), compare_person);

  solution();
}
