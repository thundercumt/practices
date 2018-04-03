#include <iostream>
#include <queue>
#include <string>

using namespace std;


struct msg {
  string m;
  int param;
  int prio;
  
  bool operator< (const msg& a) const {
    return prio > a.prio;
  }
};

priority_queue<msg> q;

int main() {
  string s;
  string m;
  int para;
  int prio;

  while (getline(cin, s)) {
    if (s == "") {
      cout << "OOPS" << endl;
      continue;
    }

    if ("GET" == s) {
      if (q.empty()) cout << "EMPTY QUEUE!" << endl;
      else {
        msg t = q.top();
        q.pop();
        cout << t.m << " " << t.param << endl;
      }
    }
    else {
      msg t;
      
      size_t i, j;
      i = s.find(' ');
      while(s[i+1]==' ') i++;
      j = i+1;
      while(s[j+1]!= ' ') j++;
      m = s.substr(i, j-i+1);

      t.m = m;

      i = j+1;
      while(s[i+1]==' ') i++;
      j = i+1;
      while(s[j+1]!= ' ') j++;
      m = s.substr(i, j-i+1);

      t.param = stoi(m);

      i = j+1;
      while(s[i+1]==' ') i++;
      j = i+1;
      while(j+1 < s.size() && (s[j+1]!= ' ' || s[j+1]!='\n')) j++;

      if (j >= s.size()) j = s.size() - 1;
      m = s.substr(i, j-i+1);

      t.prio = stoi(m);
      
      q.push(t);
    }
  }

}
