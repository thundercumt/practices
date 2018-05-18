#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

enum { NC=52, NS=4 };

class card {
  friend ostream& operator<< (ostream& os, const card& obj);
  
public:
  explicit card(char n=0) : value(n){
  }

  void operator=(char n) {
    value = n;
  }

private:
  char value;

  static string values[NC/NS + 1];
  static string suites[NS+1];
};

string card::values[] = {
  "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
};

string card::suites[] = {"Clubs", "Diamonds", "Hearts", "Spades" };


ostream& operator<<(ostream& os, const card& obj) {
  char v = obj.value; //0 based;
  os << card::values[v % 13] << " of " << card::suites[v / 13] << '\n';
  return os;
}

char deck[NC];
char deck1[NC];

int main() {

  int ns, i, j, shf;

  vector< vector<char> > shuffles;

  cin >> ns;

  
  for (i=0; i<ns; ++i) {
    shuffles.push_back(vector<char>());
    for (j=0; j<NC; ++j) {
      cin >> shf;
      shuffles[i].push_back(shf-1);//change to zero-based
    }
  }

  for (i=0; i<sizeof(deck)/sizeof(char); ++i) {
    deck[i] = i;
  }

  char * rdeck = deck;
  char * wdeck = deck1;
  card c;
  int output_cnt = -1;
  while (cin >> shf) {
    ++output_cnt;
    vector<char> vshf = shuffles[shf-1];

    for (i=0; i<NC; ++i) {
      wdeck[i] = rdeck[vshf[i]];
    }

    if (output_cnt) cout << "\n";
    for (i=0; i<NC; ++i) {
      c = wdeck[i];
      cout << c;
      //cout << (int)wdeck[i] << " ";
    }
    
    char * tmp = wdeck;
    wdeck = rdeck;
    rdeck = tmp;
  }

  return 0;
}
