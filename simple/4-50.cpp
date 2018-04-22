#include <iostream>
#include <string>

using namespace std;

const int N = 1000;

short v[N+1];

//records length of longest orderred subsequence(LOS) in range [i,end] where v[i] is included
short seq_len[N+1];

//records one (not unique) choice to support seq_len[i], the next index after i in the LOS
//-1 means no next number
short choice[N+1];

int main() {

  int n, i, j, k;
  string s;
  
  cin >> n;

  getline(cin, s);//trailing \n

  for (i=0; i<n; i++) {
    if (i) cout << "\n"; //blank line between output
    
    getline(cin, s);//blank line

    cin >> k;

    for (j=0; j<k; j++) {
      cin >> v[j];
    }


    //init the end of list
    seq_len[k-1] = 1;
    choice[k-1] = -1;

    int p, bst_opt;
    for (j=k-2; j>=0; j--) {

      //loop for the rest numbers to find a LOS that contains v[j]
      bst_opt = -1;
      for (p = j+1; p<=k-1; p++) {
        if (v[p] > v[j]) {
          if (bst_opt == -1) bst_opt = p;
          else if (seq_len[bst_opt] < seq_len[p]) bst_opt = p;
        }
      }

      if (bst_opt == -1) {
        seq_len[j] = 1;
        choice[j] = -1;
      }
      else {
        seq_len[j] = seq_len[bst_opt] + 1;
        choice[j] = bst_opt;
      }
    }

    bst_opt = 0;
    for (j=1; j<k; j++) {
      if (seq_len[bst_opt] < seq_len[j])
        bst_opt = j;
    }
    cout << seq_len[bst_opt] << "\n";
  }

  return 0;
}
