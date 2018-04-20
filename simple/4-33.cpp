#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib>

using namespace std;

int main() {
  int n;
  string s, s1, s2;
  string::iterator it;
  int a, b;

  size_t c;

  cin >> n;
  getline(cin, s);

  for (int i=0; i<n; i++) {
    getline(cin, s);

    s1.clear();
    s2.clear();
    
    c = s.find_first_of(" \n");

    if (c == string::npos) c = s.size();
    
    s1 = s.substr(0, c);

    it = s.begin() + c;
    while(it != s.end() && *it == ' ') it++;

    if (it != s.end()) {
      s2 = s.substr(it-s.begin(), s.end()-it);
    }

    a = atoi(s1.c_str());
    b = s2.size() > 0 ? atoi(s2.c_str()) : INT_MAX; 

    cout << (a >= b ? "MMM BRAINS" : "NO BRAINS") << endl;
    
  }

  

}
