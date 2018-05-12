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

    if (count == hand) {
      sort_cards();
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
      same_fig = 41;
      break;
    case 3:
      if (tmp[1] == 2)
        same_fig = 32;
      else
        same_fig = 31;
      break;
    case 2:
      if (tmp[1] == 2)
        same_fig = 22;
      else
        same_fig = 21;
      break;
    case 1:
      same_fig = 11;
      break;
    }

    return same_fig;
  }

  int figure_by_cnt(int cnt, int start=0) {
    for (int i=start; i<hand; i++) {
      if (same_fig_cnt[rank_card(figure[i])] == cnt) return i;
    }

    cout << "not found in figure_by_cnt(" << cnt << ", " << start << endl;
    return -1;
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

  int rank_hand() {
    char sm_fig = check_same_figure();
    char sm_suite = same_suite;
    char successv = successive();

    if (successv && same_suite) {
      return 9;
    }

    if (sm_fig > 40) {
      return 8;
    }

    if (sm_fig == 32) {
      return 7;
    }

    if (same_suite) {
      return 6;
    }

    if (successv) {
      return 5;
    }

    if (sm_fig == 31) {
      return 4;
    }

    if (sm_fig == 22) {
      return 3;
    }

    if (sm_fig == 21) {
      return 2;
    }

    return 1;
  }

  int compare_hand(PokerHand& p) {
    int rank1 = rank_hand();
    int rank2 = p.rank_hand();

    int i, j;
    if (rank1 == rank2) {
      switch (rank1) {
      case 9:
        i = 0;
        j = 0;
        break;
      case 8:
        i = figure_by_cnt(4);
        j = p.figure_by_cnt(4);
        break;
      case 7:
        i = figure_by_cnt(3);
        j = p.figure_by_cnt(3);
        break;
      case 6:
        for (i=0,j=0; i<hand-1 && figure[i]==p.figure[j]; ++i, ++j);
        break;
      case 5:
        i = 0;
        j = 0;
        break;
      case 4:
        i = figure_by_cnt(3);
        j = p.figure_by_cnt(3);
        break;
      case 3:
        i = figure_by_cnt(2);
        j = p.figure_by_cnt(2);
        if (figure[i] != p.figure[j]) {
          break;
        }
        
        i = figure_by_cnt(2, i+2);
        j = p.figure_by_cnt(2, j+2);
        if (figure[i] != p.figure[j]) {
          break;
        }

        i = figure_by_cnt(1);
        j = p.figure_by_cnt(1);
        break;
        
      case 2:
        i = figure_by_cnt(2);
        j = p.figure_by_cnt(2);
        if (figure[i] != p.figure[j]) {
          break;
        }
        i = -1, j=-1;
        for (int k=0; k<2; ++k) {
          i = figure_by_cnt(1, i+1);
          j = p.figure_by_cnt(1, j+1);
          //cout << figure[i] << "<>" << p.figure[j] << endl;
          if (figure[i] != p.figure[j])
            goto return_rank_card_diff;
        }

        i = figure_by_cnt(1, i+1);
        j = p.figure_by_cnt(1, j+1);
        break;
      case 1:
        for (i=0,j=0; i<hand-1 && figure[i]==p.figure[j]; ++i,++j);
        break;
      }

    return_rank_card_diff:
      return rank_card(figure[i]) - rank_card(p.figure[j]);
    }
    else {
      return rank1 - rank2;
    }
  }
   
	
  char figure[hand];
  char suite[hand];
  int count;

  char same_suite;
  char succ;
  char same_fig;
  char same_fig_cnt[radix+1];
};

void examine_hand(PokerHand& p);

int main() {
  PokerHand p1;
  PokerHand p2;
  int i;
  char c1, c2;
  while (cin >> c1 >> c2) {
    p1.clear();
    p2.clear();

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

    //examine_hand(p1);
    //examine_hand(p2);
    
    i = p1.compare_hand(p2);

    if (i > 0)
      cout << "Black wins.\n";
    else if (i < 0)
      cout << "White wins.\n";
    else
      cout << "Tie.\n";

    //cout << endl;
  }
}

void examine_hand(PokerHand& p) {
  for (int i=0; i<PokerHand::hand; i++) {
    if (i) cout << ' ';
    cout << p.figure[i] << p.suite[i];
    if (i==PokerHand::hand-1) cout << '\n';
  }  
  cout << "hand rank is " << p.rank_hand() << endl;
}
