#include <bits/stdc++.h>
using namespace std;
bool solve() {
  int N;
  cin >> N;
  if( N == 0 ) return false;
  vector<int> u(N-1), v(N-1), d(N-1);
  vector<vector<int>> G(N, vector<int>());
  for( int i = 0; i < N-1; i++ ) {
    int p;
    cin >> p;
    p--;
    u[i] = i, v[i] = p;
    G[p].push_back(i);
    G[i].push_back(p);
  }
  for( int i = 0; i < N-1; i++ ) {
    cin >> d[i];
  }
  int INF = 1<<30, ans = INF;
  for( int root = 0; root < N; root++ ) {
    vector<int> dp(N, INF);
    dp[root] = 0;
    auto dfs = [&](auto dfs, int cur, int e_pre) -> void {
      int pre = -1;
      if( e_pre != -1 ) pre = u[e_pre]^v[e_pre]^cur;
      for( int e : G[cur] ) {
        int nxt = u[e]^v[e]^cur;
        if( nxt != pre ) {
          dfs(dfs, nxt, e);
        }
      }
      if( e_pre != -1 ) {
        int pre = u[e_pre]^v[e_pre]^cur;
        if( G[cur].size() ) {
          dp[pre] += d[e_pre];
        }else {
          dp[pre] += 3*d[e_pre];
        }
      }
    };
    int d_max = 0;
    for( int e  : G[root] ) {
      ans = min(ans, dp[root]-d[e]);
    }
  }
  cout << ans << endl;
  return true;
}
int main() {
  while( solve() ) {}
}