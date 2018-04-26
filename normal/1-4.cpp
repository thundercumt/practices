#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const char nums [10][5][4] = {
  { " - ",
    "| |",
    "   ",
    "| |",
    " - "
  },

  { "   ",
    "  |",
    "   ",
    "  |",
    "   "
  },

  { " - ",
    "  |",
    " - ",
    "|  ",
    " - "
  },

  { " - ",
    "  |",
    " - ",
    "  |",
    " - "
  },

  { "   ",
    "| |",
    " - ",
    "  |",
    "   "
  },

  { " - ",
    "|  ",
    " - ",
    "  |",
    " - "
  },

  { " - ",
    "|  ",
    " - ",
    "| |",
    " - "
  },

  { " - ",
    "  |",
    "   ",
    "  |",
    "   "
  },

  { " - ",
    "| |",
    " - ",
    "| |",
    " - "
  },

  { " - ",
    "| |",
    " - ",
    "  |",
    " - "
  }
};

const int N = 10;
const int MAX_ROW = N * 2 + 3 + 1;
const int MAX_COL_ALL = (N + 2) * 8 + 7 + 1;

char v[MAX_ROW][MAX_COL_ALL] = {0};

static void fill(int digit, int rs, int cs, int s);

int main() {
  int s, i, j, row, col, col_all;
  string n;

  while (cin >> s >> n) {
    if (!s && n=="0") break;

    //memset(v, '@', MAX_ROW * MAX_COL_ALL);

    row = s * 2 + 3;
    col = s + 2;
    col_all = col * n.size() + n.size() - 1;

    for (i=0; i<n.size(); i++) {
      fill(n[i]-'0', 0, col*i + i, s);
    }

    for (i=0; i<row; i++) {
      for (j=0; j<col_all; j++) {
        cout << v[i][j];
      }
      cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}


void fill(int d, int rs, int cs, int s) {
  int i, j;
  int rlen = 2*s+3;
  int clen = s+2;

  v[rs][cs] = nums[d][0][0];
  v[rs][cs+clen-1] = nums[d][0][2];
  for (i=1; i<clen-1; i++) v[rs][cs+i] = nums[d][0][1];

  v[rs+s+1][cs] = nums[d][2][0];
  v[rs+s+1][cs+clen-1] = nums[d][2][2];
  for (i=1; i<clen-1; i++) v[rs+s+1][cs+i] = nums[d][2][1];
  
  v[rs+rlen-1][cs] = nums[d][4][0];
  v[rs+rlen-1][cs+clen-1] = nums[d][4][2];
  for (i=1; i<clen-1; i++) v[rs+rlen-1][cs+i] = nums[d][4][1];

  for (i=1; i<s+1; i++) {
    v[rs+i][cs] = nums[d][1][0];
    v[rs+i][cs+clen-1] = nums[d][1][2];
    for (j=1; j<clen-1; j++) v[rs+i][cs+j] = nums[d][1][1];
  }

  for (i=s+2; i<rlen-1; i++) {
    v[rs+i][cs] = nums[d][3][0];
    v[rs+i][cs+clen-1] = nums[d][3][2];
    for (j=1; j<clen-1; j++) v[rs+i][cs+j] = nums[d][3][1];
  }

  //add space between digits
  for (i=0; i<rlen; i++)
    v[rs+i][cs+clen] = ' ';
}
