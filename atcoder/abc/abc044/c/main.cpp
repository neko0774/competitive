#include <bits/stdc++.h>
using namespace std;
#define ll long long


void show(vector<vector<ll>> A){
  for(int i=0;i<A.size();i++){
    for(int j=0;j<50;j++){
      cout << A[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(){
  int N, A;
  cin >> N >> A;
  vector<ll> X(N);
  for(int i=0;i<N;i++){
    cin >> X[i];
  }

  vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1, vector<ll>(N*A+1, 0)));
  for(int i=0;i<N;i++){
    dp[i][0][0] = 1;
    for(int j=0;j<N;j++){
      for(int k=0;k<N*A+1;k++){
        if(k-X[i]>=0) dp[i+1][j+1][k] += dp[i][j][k-X[i]];
        dp[i+1][j][k] += dp[i][j][k];
      }
    }
  }
  ll ans = 0;
  for(int i=1;i<N+1;i++){
    ans += dp[N][i][A*i];
  }
  cout << ans << endl;
}