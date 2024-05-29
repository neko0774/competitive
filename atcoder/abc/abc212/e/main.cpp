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
  ll sum = 1;
  for(int j=0;j<K;j++){
    vector<ll> red(N);
    ll memo = 0;
    for(auto [u, v]: G){
      red[u] += dp[j][v];
      red[v] += dp[j][u]; 
    }
    for(int i=0;i<N;i++){
      dp[j+1][i] += sum-red[i];
      dp[j+1][i] %= mod;
      memo += dp[j+1][i];
      memo %= mod;
    }
    sum = memo;
  }
  cout << dp[K][0] << endl;
}