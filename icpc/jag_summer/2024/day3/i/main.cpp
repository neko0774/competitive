#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector G(N, vector<pair<int, ll>>());
  for(int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
  }

  const ll INF = 1LL << 58;
  vector dp(N, vector<ll>(2, -INF));
  auto dfs = [&](auto dfs, int cur, int pre) -> void {
    bool is_leaf = true;
    ll sum0 = 0;
    for(const auto &[nxt, co] : G[cur]) {
      if(nxt == pre) continue;
      is_leaf = false;
      dfs(dfs, nxt, cur);
      sum0 += min(co, dp[nxt][0]);
    }

    if(is_leaf) {
      dp[cur][0] = dp[cur][1] = a[cur];
    }
    else {
      dp[cur][0] = sum0 + a[cur];
      for(const auto &[nxt, co] : G[cur]) {
        if(nxt == pre) continue;
        dp[cur][1] = max(dp[cur][1], a[cur] + sum0 - min(co, dp[nxt][0]) + dp[nxt][0]);
        dp[cur][1] = max(dp[cur][1], a[cur] + sum0 - min(co, dp[nxt][0]) + min(co, dp[nxt][1]));
      }
    }
  };

  dfs(dfs, 0, -1);
  cout << max(dp[0][0], dp[0][1]) << endl;
}