#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class CompBy1Asc{
public:
  bool operator() (const string& s1, const string& s2) {
    return count(s1.begin(), s1.end(), '1') < count(s2.begin(), s2.end(), '1');
  }
};

int main() {
  multiset<string, CompBy1Asc> set;
  multiset<string>::iterator it;
  string s;

  while (cin >> s) {
    set.insert(s);
  }

  for (it=set.begin(); it!=set.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
