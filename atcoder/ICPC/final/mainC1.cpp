#include<bits/stdc++.h>
using namespace std;

int main() {
  constexpr int offset = 1000;
  constexpr int MAX = 1000;
  constexpr int SIZE = 2 * MAX + 1;
  vector<vector<int>> dp(SIZE, vector<int>(SIZE, 100000000));
  queue<pair<int, int>> que;
  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}, {-1, 1}};
  auto ok = [&](int r, int c) -> bool {
    if(-MAX <= r && r <= MAX && -MAX <= c && c <= MAX) return true;
    return false;
  };
  que.push(make_pair(0, 0));
  dp[offset][offset] = 0;
  while(!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    // if(abs(r) <= 5 && abs(c) <= 5) {
    //   cout << r << " " << c << " : " << dp[r + offset][c + offset] << endl;
    // }
    for(auto [dr, dc] : dir) {
      int r2 = r + dr, c2 = c + dc;
      if(ok(r2, c2) && dp[r + offset][c + offset] + 1 < dp[r2 + offset][c2 + offset]) {
        dp[r2 + offset][c2 + offset] = dp[r + offset][c + offset] + 1;
        que.push(make_pair(r2, c2));
      }
    }
  }
  int t;
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    cout << dp[x + offset][y + offset] << "\n";
  }
}