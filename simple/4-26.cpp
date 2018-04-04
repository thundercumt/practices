#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 5000;

char tbl[N][N];

//be careful that int i,j, not size_t i,j
//otherwise (int) -1 > (size_t)0 will pass (the cond in m>=i)
bool palindrome(const string& s, int i, int j) {
  if (i == j) return true;

  if (tbl[i][j] != '?') {
    return tbl[i][j];
  }


  if ((j-i)==1 && s[i] == s[j]) {
    tbl[i][j] = 1;
    return true;
  }
  else if ((j-i) > 1 && palindrome(s, i+1, j-1) && s[i] == s[j]) {
    tbl[i][j] = 1;
    return true;
  }
  else {
    tbl[i][j] = 0;
    return false;
  }
}

//@require 0<n<N
void init_table(int n) {
  for (int i=0; i<n; i++) {
    memset(tbl[i], '?', n);
  }
}

int main() {
  string s;
  int i, j;
  int c;

  while (cin >> s) {
    c = 0;

    init_table(s.size());
    
    for (j=0; j<s.size(); j++) {
      for (i=0; (i+j) < s.size(); i++) {
        if (palindrome(s, i, i+j)) c++; 
      }
    }
    cout << c << endl;
  }
}
