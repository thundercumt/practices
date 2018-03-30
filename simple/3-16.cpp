#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_CLASS = 20;
const int MAX_COURSE = 10;
const int MAX_STUDENT = 50;
const int SCORE_THRESHOLD = 60;


class student {
public:
  explicit student(const string& name, const double gpa)
    : _name(name), _gpa(gpa) {}

  const string& name() const {
    return _name;
  }

  const double gpa() const {
    return _gpa;
  }
      
private:
  string _name;
  double _gpa;
};


//those with greater gpa are ranked in front, if same gpa then in name ascii order
bool compare_student(const student& a, const student& b) {
  return a.gpa() != b.gpa() ? a.gpa() > b.gpa() : a.name() < b.name();
}

double student_gpa(const vector<int>& cpv, const vector<int>& spv) {
  double s = 0;
  for(int i=0; i<cpv.size(); i++) {
    s += spv[i] >= 60 ? (spv[i] - 50) * ((double)cpv[i] / 10) : 0;
  }
  return s / 10;
}

vector<student> sv;
vector<int> pv;

int main() {
  int n_cls, n_crs, n_stu;
  int i, j, k, l, p;

  vector<student> sv;
  vector<student>::iterator it;

  vector<int> cpv;
  vector<int> spv;
  string name;
  double gpa;

  cin >> n_cls;

  for (i=0; i<n_cls; i++) {

    sv.clear();
    cpv.clear();
    cin >> n_crs;

    for (j=0; j<n_crs; j++) {
      cin >> p;
      cpv.push_back(p);
    }

    cin >> n_stu;
    for (k=0; k<n_stu; k++) {
      spv.clear();
      
      cin >> name;
      for (l=0; l<n_crs; l++) {
        cin >> p;
        spv.push_back(p);
      }
      gpa = student_gpa(cpv, spv);
      sv.push_back(student(name, gpa));
    }

    sort(sv.begin(), sv.end(), compare_student);

    cout << "class " << i+1 << ":" << endl;
    for (it=sv.begin(); it!=sv.end(); it++) {
      //some issues with formatted output!!!!
      cout << fixed << setprecision(2);
      cout << left << setw(11);
      cout << it->name() << it->gpa() << endl;
    }
    cout << (i ? "\n" : "");
  }
  
}
