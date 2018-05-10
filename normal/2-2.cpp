#include <iostream>
#include <cstddef>

using namespace std;

struct PokerHand {
	
	enum { hand=5 };
	
	PokerHand() : count(0), same_suite(true) {}
	
	void add(char fig, char sweet) {
		if (count < hand) {
			if (same_suite && cout > 0 && suite[count-1] != sweet) {
				same_suite = false;
			}
			
			figure[count] = fig;
			suite[count] = sweet;
			++count;
		}
	}
	
	int rank_card(int i) {
		switch (figure[i]) {
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
		}
	}
	
	int rank_hand() {
		
	}
	
	void inline copy(int i, int j) {
		
	}
	
	void sort() {
		char c1, c2;
		int r, i, j;
		for (i=1; i<hand; ++i) {
			r = rank_card(i);
			c1 = figure[i];
			c2 = suite[i];

			for(j=i-1; j>=0; --j) {
				if (r > rank_card(j)) {
					figure[j+1] = figure[j];
					suite[j+1] = suite[j];
				}
				else {
					break;
				}
			}
			
			figure[j+1] = c1;
			suite[j+1] = c2;
		}
		
		/*
		for (int i=0; i<hand; ++i)
			cout << figure[i] << suite[i] << ' ';
		cout << endl;
		*/
	}
	
	bool tong_hua_shun() {
		
		
		
	}
	
	
	char figure[hand];
	char suite[hand];
	int count;
	bool same_suite;
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
		
		p1.sort();
		p2.sort();
	}
}