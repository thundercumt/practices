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
  string cmd, m;
  int para, pri;

  ios::sync_with_stdio(false);

  while (cin >> cmd) {
    if ("GET" == cmd) {
      if (q.empty()) cout << "EMPTY QUEUE!" << endl;
      else {
        msg t = q.top();
        q.pop();
        cout << t.m << " " << t.param << endl;
      }
    }
    else {
      cin >> m >> para >> pri;
      msg t;
      t.m = m;
      t.param = para;
      t.prio = pri;
      q.push(t);
    }
  }
}
