#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> dp(N, vector<ll>(2, 0));
  vector<vector<vector<ll>>> G(N, vector<vector<ll>>());
  int u, v, b, c;
  for(int i=0;i<N;i++){
    cin >> u >> v >> b >> c;
    u--;
    v--;
    G[u].push_back({v, b, c});
  }
  for(int i=0;i<N;i++){
    for(auto vec: G[i]){
      ll to = vec[0], b = vec[1], c = vec[2];
      ll nb = dp[to][0], nc = dp[to][1], cb = dp[i][0], cc = dp[i][1];
      if(nc==0 || nb*(cc+c)<nc*(cb+b)){
        dp[to][0]=cb+b;
        dp[to][1]=cc+c;
      }
    }
  }
  for(int i=0;i<N;i++){
    cout << dp[i][0] << ' ' << dp[i][1] << endl;
  }
  cout << setprecision(10) << (long double)dp[N-1][0]/(long double)dp[N-1][1]<<endl;
}