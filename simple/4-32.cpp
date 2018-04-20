#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

const int N = 8000;

struct dt {
  short y;
  char m;
  char d;

  dt(int y, char m, char d):y(y), m(m), d(d) {}
  dt() {}
};

string days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};


inline bool leap(int y) {
  return (y % 400) == 0 || ((y % 100) != 0 && (y % 4) == 0);
}


dt dates[N * 366];


int main() {
  int n = N * 366;
  int y,m,d,dd;
  bool lp;

  y=2000, m=1, d=1;
  for (int i=0; i<=n; i++) {
    if (y > 9999) break;
    
    dates[i] = dt(y, m, d);

    lp = leap(y);

    d++;
    
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
      if (d==32) {
        m++;
        d = 1;
      }
    }
    else if (m==2) {
      if (lp && d==30) {
        m++;
        d = 1;
      }
      else if (!lp && d==29) {
        if (y==2004) cout << lp << " " << y << endl;
        m++;
        d = 1;
      }
    }
    else if (m==4 || m==6 || m==9 || m==11) {
      if (d==31) {
        m++;
        d = 1;
      }
    }

    if (m==13) {
      y++;
      m = 1;
    }
  }


  while (true) {
    cin >> n;

    if (n == -1) break;

    dt today = dates[n];//n is elapsed dates
    y = today.y;
    m = today.m;
    d = today.d;
    dd = n % 7;

    cout << y << "-" << setw(2) << setfill('0') << m << "-" << setw(2) << setfill('0') <<  d << " " << days[dd] << endl;
    
  }
  
}
