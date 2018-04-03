#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct book {

  book(const string& nm, int y, int p): name(nm), year(y), price(p){}
  string name;
  int year;
  int price;
};

bool name_order(const book& a, const book& b) {
  if (a.name != b.name) return a.name < b.name;
  if (a.year != b.year) return a.year < b.year;
  return a.price < b.price;
}

bool year_order (const book& a, const book& b) {
  if (a.year != b.year) return a.year < b.year;
  if (a.name != b.name) return a.name < b.name;
  return a.price < b.price;
}

bool price_order (const book& a, const book& b) {
  if (a.price != b.price) return a.price < b.price;
  if (a.name != b.name) return a.name < b.name;
  return a.year < b.year;
}

vector<book> v;

int main() {
  int n, i;
  string nm, st; int y, p;
  vector<book>::iterator it;
  int r=0;

  while (true) {
    cin >> n;

    if (!n) break;

    v.clear();
    for (i=0; i<n; i++) {
      cin >> nm >> y >> p;
      v.push_back(book(nm, y, p));
    }
    cin >> st;

    if ("Name" == st)
      sort(v.begin(), v.end(), name_order);
    else if ("Year" == st)
      sort(v.begin(), v.end(), year_order);
    else
      sort(v.begin(), v.end(), price_order);

    if (r) cout << endl;
    for (it=v.begin(); it!=v.end(); it++) {
      cout << it->name << " " << it->year << " " << it->price << endl;
    }

    r++;								 
  }

  return 0;
}
