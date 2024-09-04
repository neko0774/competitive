#include<bits/stdc++.h>
using namespace std;

int dfs(int l, int r, vector<int> &W, vector<vector<int>> &dp){
  if(dp[l][r]!=-1) return dp[l][r];
  if(r-l<=1) return 0;
  if(r-l==2){
    if(abs(W[l]-W[r-1])<=1) return 2;
    return 0;
  }
  if(dfs(l+1, r-1, W, dp)==r-l-2&&abs(W[l]-W[r-1])<=1){
    dp[l][r] = r-l;
    return dp[l][r];
  }
  for(int i=l+1;i<r;i++){
    dp[l][r] = max(dp[l][r], dfs(l, i, W, dp)+dfs(i, r, W, dp));
  }
  //cout << l << ' ' << r << ' ' << dp[l][r] << endl;
  return dp[l][r];
} 

bool solve(){
  int N;
  cin >> N;
  if(N==0) return false;
  vector<int> W(N);
  for(int i=0;i<N;i++){
    cin >> W[i];
  }
  vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
  //dp[l, r) max 
  cout << dfs(0, N, W, dp) << endl;
  return true;
}

int main(){
  while(solve()){}
}

