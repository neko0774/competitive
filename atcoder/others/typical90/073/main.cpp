#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;


void dfs(vector<vector<ll>> &dp, int x, int pre, vector<vector<ll>> &G, vector<char> &C){
  if(G[x].size()==1){
    if(C[x]=='a') dp[x][1]++;
    else dp[x][2]++;
  }
  for(auto nx: G[x]){
    if(pre==nx) continue;
    dfs(dp, nx, x, G, C);
    if(C[x]=='a'){
      dp[x][0] += dp[nx][0]+dp[nx][2];
      dp[x][1] += dp[nx][0]+dp[nx][1];
      dp[x][2] += dp[nx][0];
    }else{
      dp[x][0] += dp[nx][0]+dp[nx][1];
      dp[x][1] += dp[nx][0];
      dp[x][2] += dp[nx][0]+dp[nx][2];
    }
    for(int i=0;i<3;i++){
      dp[x][3] %= mod;
    }
  }
}

int main(){
  int N;cin >> N;
  vector<char> C(N);
  vector<vector<ll>> dp(N, vector<ll>(3, 0)), G(N, vector<ll>());
  for(int i=0;i<N;i++){
    cin >> C[i];
  }
  int u, v;
  for(int i=0;i<N-1;i++){
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(dp, 0, -1, G, C);
  cout << dp[0][0] << endl;

}