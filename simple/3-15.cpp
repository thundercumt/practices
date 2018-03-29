#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool symmetric(const string& s) {
  string::const_iterator it1, it2;

  if (s.size() == 0) return false; //assume empty string is not symmetric

  for (it1=s.begin(), it2=s.end() - 1; //s is not empty => s.end() - 1 points to the last item
       it1 < it2;
       it1++, it2--) {
    if (*it1 != *it2) break;
  }

  return it1 < it2 ? false : true;
}


class StringCompare {
public:
  bool operator() (const string& s1, const string& s2) {
    return s1.size() != s2.size() ? s1.size() < s2.size() : s1 < s2;
  }
};


int main() {
  multiset<string, StringCompare> ms;
  string s;
  multiset<string>::iterator it;

  while (cin >> s) {
    if (symmetric(s)) {
      ms.insert(s);
    }
  }

  for (it=ms.begin(); it!=ms.end(); it++) {
    cout << *it << endl;
  }
}
