#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

const int N = 100;
const int NC = 26 + 1;

std::vector<std::string> v;
std::map<char, char> code;

void try_map_code(const std::string& s, const std::string& ref) {
  assert(s.size() == ref.size());

  if (code.size() > 0) return;
  
  int sz = s.size();
  char c1, c2;
  int t;
  for (int i=0; i<sz; ++i) {
    c1 = s[i], c2 = ref[i];

    t = code.count(c1);
    if (!t) {
      code[c1] = c2;
    }
    else if (t && code[c1] == c2) {
      continue;
    }
    else {
      code.clear();
      return;
    }
  }
}

int main() {

  int i, j;
  std::string s;
  const std::string ref("the quick brown fox jumps over the lazy dog");

  i = -1;
  while (std::getline(std::cin, s)) {
    ++i;
    if (i) std::cout << '\n';
    v.clear();
    code.clear();

    v.push_back(s);
    if (s.size() == ref.size()) try_map_code(s, ref);

    while(std::getline(std::cin, s)) {
      if (s.size() == 0) break;//next case;

      v.push_back(s);
      if (s.size() == ref.size()) try_map_code(s, ref);
    }

    if (code.size() > 0) {
      for (j=0; j<v.size(); ++j) {
        std::string &t = v[j];
        for (int c=0; c<t.size(); ++c) {
          std::cout << code[t[c]];
        }
        std::cout << '\n';
      }
    }
    else {
      std::cout << "No solution.\n";
    }
  }
}
