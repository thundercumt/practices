#include <iostream>
#include <cstring>

using namespace std;

const int N_DAYS = 3650;
const int N_PARTY = 100;

char days[N_DAYS+1] = {0};
short party[N_PARTY+1] = {0};

int main() {

  int c, i, j, n_days, n_party;
  short interval;
  int d;

  cin >> c;

  for (i=0; i<c; ++i) {
    cin >> n_days >> n_party;

    memset(days, 0, n_days+1);
    memset(party, 0, n_party+1);

    for (j=0; j<n_party; ++j) {
      cin >> party[j];
    }

    for (j=0; j<n_party; ++j) {
      interval = party[j];
      for (int d=interval-1; d<n_days; d+=interval) {
        days[d] = 1;
      }
    }

    d = 0;
    for (j=0; j<n_days; ++j) {
      if (days[j] && j%7!=5 && j%7!=6) d++;
    }

    cout << d << '\n';
  }
}
