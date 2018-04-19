#include <iostream>
#include <string>

using namespace std;

const char ROOT = '\0';

template<unsigned int radix>
struct trie_node {
  trie_node(char ch) : v(ch), leaf(false) {
    for (int i=0; i<radix; i++)
      c[i] = 0;
  }

  ~trie_node() {
    for (int i=0; i<radix; i++) {
      if (c[i]) {
        c[i]->~trie_node();
        c[i] = 0;
      }
    }
  }

  bool empty() {
    bool l = true;
    for (int i=0; i<radix; i++)
      l &= (c[i]==0);
    return l;
  }
  
  /*
   * return 0, 1; 1 means new node, otherwise prefix node exists;
   */
  int add(const char* p, int n) {
    if (leaf) {
      return 0;//substring met;
    }
    else if (!n) {
      if (empty()) {
        leaf = 1;
        return 1;
      }
      else {
        return 0;//containing string met;
      }
    }
    else {
      char ch = *p;
      trie_node *node = c[ch - '0'];

      if (!node) {
        c[ch - '0'] = new trie_node(ch);
      }
      node = c[ch - '0'];
      return node->add(p+1, n-1);
    }  
  }

  void clear(bool as_leaf) {
    for (int i=0; i<radix; i++) {
      if (c[i]) {
        c[i]->~trie_node();
        c[i] = 0;
      }
    }
    leaf = as_leaf;
  }

  void debug() {
    cout << v;
    if (leaf) cout << endl;
    for (int i=0; i<radix; i++) {
      if (c[i]) c[i]->debug();
    }
  }

  char v;
  bool leaf;
  trie_node* c[radix];
};


int main() {
  trie_node<10> r(ROOT);

  int t, n;
  int i, j;
  string s;

  cin >> t;

  for (i=0; i<t; i++) {
    r.clear(false);
    cin >> n;

    int added = 1;
    for (j=0; j<n; j++) {
      cin >> s;
      added = r.add(s.c_str(), s.size());

      if (!added) {
        break;
      }
    }
    cout << (added ? "YES" : "NO") << endl;
  }

  return 0;
}
