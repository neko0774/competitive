#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main(){
  int N, K;
  cin >> N >> K;
  vector<ll> dp(1<<N, -INF);
  vector<vector<ll>> W(N, vector<ll>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> W[i][j];
    }
  }
  vector<ll> count(1<<N, 0);
  dp[0] = 0;
  for(int i=0;i<(1<<N);i++){
    for(int j=0;j<N;j++){
      for(int k=j+1;k<N;k++){
        if((i&(1<<j)) && (i&(1<<k))){
          count[i] += W[j][k];
        }
      }
    }
  }
  ll S = 0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      S += W[i][j];
    }
  }
  for(ll i=0;i<(1<<N);i++){
    dp[i] = count[i];
    for(ll T = i;T>0;T=(T-1)&i){
      dp[i] = max(dp[i], dp[T]+K+count[i^T]);
    }
  }
  cout << dp[(1<<N)-1]-S << endl;
}