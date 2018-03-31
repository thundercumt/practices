#include <iostream>
#include <cstring>

using namespace std;

const int N=50;

int main() {
  char buf[N+1];
  int n, i, j, l;

  cin >> n;

  //after reading 'n', trailing \n needs to be processed!!
  //otherwise the following getline reads empty
  cin.getline(buf, N);//skip the trailing \n

  for (i=0; i<n; i++) {
    memset(buf, 0, N+1);
    cin.getline(buf, N);
    l = strlen(buf);
    
    cout << "String #" << i+1 << endl;
    
    for (j=0; j<l; j++) {
      cout << (char) (buf[j]!='Z' ? buf[j]+1 : 'A');
    }
    cout << endl;
  }
  
  return 0;
}
