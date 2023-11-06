#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll ans=0;

  for(int j=1;j<N+1;j++){
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(j, vector<ll>(j+1, 0)));
    for(int i=0;i<N;i++){
      dp[i][0][0] = 1;
      for(int k=0;k<j;k++){
        for(int h=0;h<j;h++){
          dp[i+1][(k+A[i])%j][h+1] += dp[i][k][h];
          dp[i+1][(k+A[i])%j][h+1] %= MOD;
          dp[i+1][k][h] += dp[i][k][h];
          dp[i+1][k][h] %= MOD;
        }
        dp[i+1][k][j] += dp[i][k][j];
        dp[i+1][k][j] %= MOD;
      }
    }
    ans += dp[N][0][j];
    ans %= MOD;
  }
  cout << ans%MOD << endl;
}