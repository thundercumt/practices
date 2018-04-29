#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cstring>


using namespace std;

template<size_t NDig, size_t NReg, size_t NMem>
class Interpreter {
public:

  void clear() {
    memset(mem, 0, NMem * sizeof(int));
    memset(reg, 0, NReg * sizeof(int));
    cnt = 0;
    memSize = 0;
    run = false;
  }

  void readMem() {
    char line[NDig + 1] = {0};
    int code;
    int memCnt = 0;

    while (cin.getline(line, NDig + 1)) {
      if (strlen(line) == 0) break; //empty line before next case
      
      code = atoi(line);
      mem[memCnt++] = code;
    }

    memSize = memCnt;
    run = true;
  }

  size_t count() const {
    return cnt;
  }

  void debugOutput() const {
    for (int i=0; i<memSize; i++) {
      cout << i << "\t\t" << mem[i] << '\n';
    }
    cout << '\n';

    for (int i=0; i<NReg; i++) {
      cout << i << "\t\t" << reg[i] << '\n';
    }

    cout << endl;
  }
  
  void execute() {
    int code, fst, snd, thd, r;

    run = true;
    size_t ip = 0;
    
    while(run) {
      if (ip < 0 || ip >= NMem) break;
      cnt++;

      code = mem[ip];

      fst = code / 100;
      snd = code / 10 % 10;
      thd = code % 10;

      switch (fst) {
      case 1:
        if (!snd && !thd) {
          run = false;
        }
        break;
      case 2:
        reg[snd] = thd;
        break;
      case 3:
        reg[snd] = (reg[snd] + thd) % 1000;
        break;
      case 4:
        reg[snd] = (reg[snd] * thd) % 1000;
        break;
      case 5:
        reg[snd] = reg[thd];
        break;
      case 6:
        reg[snd] = (reg[snd] + reg[thd]) % 1000;
        break;
      case 7:
        reg[snd] = (reg[snd] * reg[thd]) % 1000;
        break;
      case 8:
        reg[snd] = mem[reg[thd]];
        break;
      case 9:
        mem[reg[thd]] = reg[snd];
        break;
      case 0:
        if (reg[thd]) {
          ip = reg[snd];
          continue;
        }
      }
      
      ip++;
    }
  }
private:
  size_t cnt;
  bool run;
  int reg[NReg];
  int mem[NMem];
  size_t memSize;
};


int main() {

  int n, i;
  char buf[4] = {0};
  Interpreter<3, 10, 1000> inter;

  inter.clear();
  inter.readMem();
  inter.execute();
  cout << inter.count();

  /** damn, the poj input/output is different from original uva ones
  cin >> n;
  cin.getline(buf, 4); //trailing \n
  cin.getline(buf, 4); //empty line

  for (i=0; i<n; i++) {
    inter.clear();
    inter.readMem();

    inter.execute();

    //if (i) cout << '\n';
    cout << inter.count() << '\n';
  }
  **/

}
