#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool less_string(const string& s1, const string& s2) {
  int len1, len2, num_one_1, num_one_2;

  len1 = s1.size();
  len2 = s2.size();
  
  if (len1 < len2)
    return true;

  num_one_1 = count(s1.begin(), s1.end(), '1');
  num_one_2 = count(s2.begin(), s2.end(), '1'); 
  if (len1 == len2 && num_one_1 < num_one_2)
    return true;

  if (len1 == len2 && num_one_1 == num_one_2)
    return s1 < s2;

  return false;
}


int main() {
  vector<string> v;
  string s;
  vector<string>::iterator it;

  while(cin >> s) {
    v.push_back(s);
  }

  sort(v.begin(), v.end(), less_string);

  for (it=v.begin(); it!=v.end(); it++) {
    cout << *it << endl;
  }
}
