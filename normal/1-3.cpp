#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int N = 1000;

double costs[N] = {0};

int main() {

  int n, i;
  double v, sum1, sum2, avg;

  while (cin >> n) {

    if (n == 0) break;

    avg = 0;
    for (i=0; i<n; i++) {
      cin >> v;
      costs[i] = v;
      avg += v;
    }
    avg /= n;

    avg = (floor((avg + 0.005) * 100)) / 100;//round avg to 1 cent

    sum1 = 0, sum2 = 0;
    for (i=0; i<n; i++) {
      if (costs[i] > avg)
        sum1 += costs[i] - avg;
      else
        sum2 += avg - costs[i];
    }

    //cout << "avg is " << avg <<  " sum is " << sum1 << " " << sum2 << endl;
    
    cout << '$' << fixed << setprecision(2) << min(sum1, sum2) << '\n';
  }

}
