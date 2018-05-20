#include <iostream>
#include <set>
#include <cstdlib>
#include <time.h> 

using namespace std;

int main(int argc, const char** argv) {
  if (argc != 3) {
    cout << "usage: 2-6-testgen <num_paper> <num_author>\n";
    return 0;
  }

  int num_paper = atoi(argv[1]);
  int num_author = atoi(argv[2]);
  int paper_authors, t;
  set <int> authors;

  srand(time(NULL));

  cout << num_paper << ' ' << num_author << '\n';
  
  //cout << "generating papers" << endl;
  for (int i=0; i<num_paper; ++i) {
    paper_authors = rand() % num_author;
    paper_authors %= 9;
    paper_authors += 1;
    authors.clear();

    while(authors.size() < paper_authors) {
      authors.insert(rand() % num_author);
    }

    int n = authors.size() - 1, j=0;
    set<int>::iterator it = authors.begin();
    if (i==0) cout << "Erdos, P., ";
    for (j=0; j<n && it!=authors.end(); ++it, ++j) {
      cout << "fst" << *it << ", lst" << *it << ", ";
    }
    cout << "fst" << *it << ", lst" << *it << ": ";
    cout << "Paper" << i << '\n';
  }

  //cout << "generating authors" << endl;
  for (int i=0; i<num_author; ++i) {
    cout << "fst" << i << ", lst" << i << '\n';
  }

  cout << "0 0" << endl;
}
