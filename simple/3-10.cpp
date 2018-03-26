#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const int N=32;

vector<int> v;

void decimal_to_binary(int n) {
  int i = 0;
  int nn = n;
  v.clear();
  
  while(nn != 0) {
    v.push_back(abs(nn % 2));//-1 % 2 => -1, but we want 1 here
    ++i;
    nn /= 2;
  }

  cout << setw(10) << n << "-->" << (n < 0 ? "-" : "");

  if (i > 0) {
    while(--i >= 0) {
      cout << v[i];
    }
  } else {
    cout << 0;
  }

  cout << endl;
}

int main() {
  int n;
  while(cin >> n) {
    decimal_to_binary(n);
  }
}

