#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

static const int N_CAND = 20;
static const int N_NAME = 80;
static const int N_VOTES = 1000;

static char cand[N_CAND+1][N_NAME+1] = {0};

static short ballot[N_VOTES+1][N_CAND+1] = {0};

static short ballot_offset[N_VOTES+1] = {0};

static short cand_remove[N_CAND+1] = {0};

static short cand_stat[N_CAND+1] = {0};

static void calc_votes(int n, short& max, short& min) {
  short mx = 0, mn = N_VOTES;
  for (int i=1; i<=n; i++) {
    if (cand_remove[i]) continue;
    if (cand_stat[i] > mx) mx = cand_stat[i];
    if (cand_stat[i] < mn) mn = cand_stat[i];
  }

  max = mx;
  min = mn;
}

static void split(char *s, int nc, short* vote, int ns) {
  char *end = s + nc;
  short *ve = vote + ns;

  char *e;
  while (s < end) {
    while (*s == ' ' && (s+1 < end)) s++;
    e = s;
    while(isdigit(*e) && (e+1 < end)) ++e;

    if (e - s <= 1) {//e == s when e is at the end
      if (vote < ve) {
        *vote = *s - '0';
        ++vote;
      }
    }
    else if (e - s == 2) {
      if (vote < ve) {
        *vote = *s - '0' * 10 + (*(s+1)) - '0';
        ++vote;
      }
    }
    else {
      //not possible
    }

    s = e+1;
  }
}

void debug() {
  int i;
  int n = 10;
  for (i=1; i<=n; i++) {
    cout << cand[i] << ", ";
  }
  cout << "\n\n";

  for (i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cout << ballot[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  for (i=1; i<=n; i++) {
    cout << cand_stat[i] << " ";
  }
  cout << "\n\n";
}

int main() {
  int n_cand, n_votes, i, j, t;

  short max_votes, min_votes, target_votes;

  char vote[100] = {0};

  int x = 0;
  while (cin >> n_cand) {
    ++x;
    //cout << "Case No." << x << "\n";
    if (x>1) cout << '\n';
    
    memset(ballot_offset, 0, (N_VOTES +1) * sizeof(short));
    memset(cand_remove, 0, (N_CAND + 1) * sizeof(short));
    
    cin.getline(vote, 100);//for the trailing \n
  
    for (i=1; i<=n_cand; ++i) {
      cin.getline(cand[i], N_NAME+1);
    }

    i = 0;
    while (cin.getline(vote, 100)) {
      t = strlen(vote);
      
      if (t == 0) break;
      
      ++i;//a new vote

      split(vote, t, &(ballot[i][1]), n_cand);

    }

    n_votes = i;
    target_votes = i >> 1;

    do {
      memset(cand_stat, 0, (N_CAND+1) * sizeof(short));

      for (i=1; i<=n_votes; i++) {
        j = ballot[i][  ballot_offset[i]+1 ];
        cand_stat[j]++;
      }

      calc_votes(n_cand, max_votes, min_votes);
      
      if (max_votes > target_votes) break;

      if (max_votes == min_votes) break;

      for (i=1; i<=n_cand; i++) {
        if (cand_stat[i] == min_votes && cand_remove[i] == 0) {
          cand_remove[i] = 1;
        }
      }
      
      for (i=1; i<=n_votes; i++) {
        j = ballot[i][ballot_offset[i]+1];
        while (cand_remove[j]) {
          ballot_offset[i]++;
          j = ballot[i][ballot_offset[i]+1];
        }
      }

      //debug();

    } while (max_votes <= target_votes && max_votes > min_votes);
    
    for (i=1; i<=n_cand; i++) {
      if (cand_stat[i] == max_votes) {
        cout << cand[i] << '\n';
      }
    }
  }
  
}
