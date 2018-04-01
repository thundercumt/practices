#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


inline int digit(const string& s, int i) {
  return i < s.size() ? s[i] - '0' : 0;
}


void string_add(string& sum, string s1, string& s2) {
  int c, t, i, sz1, sz2;

  sum.clear();
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  
  sz1 = s1.size();
  sz2 = s2.size();
  c = 0;
  for (i=0; true; i++) {
    t = digit(s1, i) + digit(s2, i) + c;

    if (i>=sz1 && i>=sz2 && t==0) break;

    c = t >= 10 ? 1 : 0;
    sum.push_back('0' + t % 10);
  }

  reverse(sum.begin(), sum.end());
  
  string::iterator it;
  for (it=sum.end() - 1; it != sum.begin() && *it == '0'; it--);

  it++;//point forth to a '0'
  sum.erase(it, sum.end());
}


int main() {
  string s1, s2, sum;
  int n, i;

  cin >> n;

  for (i=0; i<n; i++) {
    cin >> s1 >> s2;
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string_add(sum, s1, s2);

    reverse(sum.begin(), sum.end());
    cout << sum << endl;
  }

}
