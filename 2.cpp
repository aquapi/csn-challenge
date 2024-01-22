#include <iostream>
using namespace std;

#define MAX_INP 11

int ways[MAX_INP][MAX_INP];
void resetDPArray() {
  for (int i = 1; i < MAX_INP; ++i)
    for (int j = 1; j < MAX_INP; ++j)
      ways[i][j] = 0;

  // Base case
  for (int i = 0; i < MAX_INP; ++i)
    ways[i][0] = ways[0][i] = 1;
}

int x, y;

// Solve each test
void solve() {
  cin >> x >> y;

  for (int i = 1; i <= x; ++i)
    for (int j = 1; j <= y; ++j)
      ways[i][j] = ways[i - 1][j] + ways[i][j - 1];

  cout << ways[x][y];
}

// Preparations
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    resetDPArray();
    solve();
    cout << '\n';
  }
}
