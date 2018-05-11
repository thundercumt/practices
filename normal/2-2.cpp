#include <iostream>
#include <algorithm>
#include <functional>

#include <cstddef>
#include <cstring>

using namespace std;

struct PokerHand {
  enum { hand=5, radix = 13 };

  PokerHand() : count(0), same_suite(-1), same_fig(-1), succ(-1) {
    memset(figure, 0, hand);
    memset(suite, 0, hand);
    memset(same_fig_cnt, 0, sizeof(same_fig_cnt) / sizeof(char));
  }

  void add(char fig, char sweet) {
    if (same_suite == -1) same_suite = 1;

    if (count < hand) {
      if (same_suite == 1 && count > 0 && suite[count-1] != sweet) {
        same_suite = 0;
      }

      figure[count] = fig;
      suite[count] = sweet;
      ++count;
    }
  }
	
  int rank_card(char fig) {
    switch (fig) {
    case '2':
      return 1;
    case '3':
      return 2;
    case '4':
      return 3;
    case '5':
      return 4;
    case '6':
      return 5;
    case '7':
      return 6;
    case '8':
      return 7;
    case '9':
      return 8;
    case 'T':
      return 9;
    case 'J':
      return 10;
    case 'Q':
      return 11;
    case 'K':
      return 12;
    case 'A':
      return 13;
    default:
      cout << "error in rank_card(" << fig << ")\n";
      return -1;
    }
  }

  char unrank_card(int i) {
    switch(i) {
    case 1:
      return '2';
    case 2:
      return '3';
    case 3:
      return '4';
    case 4:
      return '5';
    case 5:
      return '6';
    case 6:
      return '7';
    case 7:
      return '8';
    case 8:
      return '9';
    case 9:
      return 'T';
    case 10:
      return 'J';
    case 11:
      return 'Q';
    case 12:
      return 'K';
    case 13:
      return 'A';
    default:
      cout << "error in unrank_card(" << i << ")\n";
      return 0;
    }
  }
	
  int rank_hand() {
		
  }
	
  void sort_cards() {
    char c1, c2;
    int r, i, j;
    for (i=1; i<hand; ++i) {
      c1 = figure[i];
      c2 = suite[i];
      r = rank_card(c1);

      for(j=i-1; j>=0; --j) {
        if (r > rank_card(figure[j])) {
          figure[j+1] = figure[j];
          suite[j+1] = suite[j];
        }
        else break;
      }

      figure[j+1] = c1;
      suite[j+1] = c2;
    }
		
    for (int i=0; i<hand; ++i)
      cout << figure[i] << suite[i] << ' ';
    cout << endl;
  }

  bool successive() {
    if (succ != -1) return succ;
    succ = 1;
    for (int i=1; i<hand; ++i) {
      if (figure[i-1] - figure[i] != 1) {
        succ = 0;
        break;
      }
    }
    return succ;
  }

  
  
  int check_same_figure() {
    if (same_fig != -1) return same_fig;

    for (int i=0; i<hand; i++) {
      same_fig_cnt[rank_card(figure[i])]++;
    }

    char tmp[hand] = {0};
    for (int i=1, j=0; i<=radix; i++) {
      if (same_fig_cnt[i]) {
        tmp[j] = same_fig_cnt[i];
        ++j;
      }
    }
    sort(tmp, tmp+hand, greater<char>());
    
    switch (tmp[0]) {
    case 4:
      return 41;
    case 3:
      if (tmp[1] == 2)
        return 32;
      else
        return 31;
    case 2:
      if (tmp[1] == 2)
        return 22;
      else
        return 21;
    case 1:
      return 11;
    }
  }

  void clear() {
    memset(figure, 0, hand);
    memset(suite, 0, hand);
    count = 0;

    same_suite = -1;
    succ = -1;
    same_fig = -1;
    memset(same_fig_cnt, 0, sizeof(same_fig_cnt) / sizeof(char));
  }
	
  char figure[hand];
  char suite[hand];
  int count;

  char same_suite;
  char succ;
  char same_fig;
  char same_fig_cnt[radix+1];
};

int main() {
  PokerHand p1;
  PokerHand p2;
  int i;
  char c1, c2;
  while (cin >> c1 >> c2) {
    p1.add(c1, c2);
    for (i=1; i<5; ++i) {
      cin >> c1 >> c2;
      p1.add(c1, c2);
    }	

    cin >> c1 >> c2;
    p2.add(c1, c2);
    for (i=1; i<5; ++i) {
      cin >> c1 >> c2;
      p2.add(c1,c2);
    }

    p1.sort_cards();
    p2.sort_cards();
  }
}
