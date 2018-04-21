#include <iostream>
#include <vector>

using namespace std;

bool match(const string& s, const string& p) {

  int pos = p.find('*');
  
  if (pos == string::npos) {
    return s == p;
  }

  //with '*' match starts
  if (p == "*") return true;

  //p starts with '*'
  if (pos == 0) {
    int n = p.size() - 1;

    if (n > s.size()) return false;
    else return s.compare(s.size() - n, n, p, 1, n) == 0; 
  }

  //p ends with '*'
  else if (pos == p.size() - 1) {
    int n = p.size() - 1;

    if (n > s.size()) return false;
    else return s.compare(0, n, p, 0, n) == 0;
  }

  //'*' in the middle of p
  else {
    
    int n1 = pos, n2 = p.size() - pos - 1;

    if ((n1+n2) > s.size()) return false;
    else return s.compare(0, n1, p, 0, n1) == 0
           && s.compare(s.size() - n2, n2, p, pos+1, n2) == 0;
  }
}



int main() {
  int nf, ns;
  vector<string> v;
  vector<string> ans;

  int i, j;
  string s;

  int caseid = 0;

  
  do {
    caseid++;
    if (caseid > 1) cout << endl;
    
    v.clear();
    cin >> nf;
    for (i=0; i<nf; i++) {
      cin >> s;
      v.push_back(s);
    }

    cin >> ns;
    for (i=0; i<ns; i++) {
      ans.clear();
      cin >> s;
      
      for (j=0; j<v.size(); j++) {
        if (match(v[j], s)) ans.push_back(v[j]);
      }

      if (ans.size() > 0) {
        for (j=0; j<ans.size(); j++) {
          if (j>0) cout << ", ";
          cout << ans[j];
        }
      }
      else {
        cout << "FILE NOT FOUND";
      }
      cout << endl;
    }

    getline(cin, s); //read the last '\n' of the last reading of search string

  } while (getline(cin, s) && !cin.eof());

}
