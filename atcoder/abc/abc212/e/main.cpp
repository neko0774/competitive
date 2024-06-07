#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<int, int>> G;
  int u, v;
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;v--;
    G.push_back(make_pair(u, v));
  }
  vector<vector<ll>> dp(K+1, vector<ll>(N, 0));
  dp[0][0] = 1;
  ll total = 1;
  for(int i=0;i<K;i++){
    vector<ll> red(N);
    ll memo = 0;
    for(auto [u, v]:G){
      red[u] += dp[i][v];
      red[v] += dp[i][u];
      red[u] %= mod;
      red[v] %= mod;
    }
    for(int j=0;j<N;j++){
        dp[i+1][j] += total-red[j]-dp[i][j];
        dp[i+1][j] %= mod;
        memo = (memo+dp[i+1][j])%mod;
    }
    total = memo;
  }
  cout << (dp[K][0]+mod)%mod << endl;
}