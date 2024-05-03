#include<bits/stdc++.h>
using namespace std;

bool is_end = false;

constexpr int K = 1010;
long long dp[1005][K];

void solve() {
  int n;
  long long m;
  cin >> n >> m;
  if( n == 0 && m == 0 ) {
    is_end = true;
    return;
  }
  vector<long long> a(n), b(n);
  for( int i = 0; i < n; i++ ) {
    cin >> a[i];
  }
  for( int i = 0; i < n; i++ ) {
    cin >> b[i];
  }
  vector<long long> d(n);
  for( int i = 0; i < n; i++ ) {
    d[i] = (b[i]-a[i]+m)%m;
  }
  constexpr long long INF = 1LL<<60;
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < K; j++ ) {
      dp[i][j] = INF;
    }
  }
  for( int j = 0; j < K; j++ ) {
    dp[0][j] = d[0]+m*j;
  }
  for( int i = 1; i < n; i++ ) {
    long long mn=INF;
    for(int j=K-1;j>=0;j--)
    {
      mn=min(mn,dp[i-1][j]); // d[i-1]+j*M
      if(j)dp[i][j-1]=min(dp[i][j-1],mn);
      if(d[i]<=d[i-1])dp[i][j]=min(dp[i][j],mn);
    }
    for(int j=0;j<K;j++)
    {
      if(j)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+d[i]+m-d[i-1]);
      if(d[i]>=d[i-1])dp[i][j]=min(dp[i][j],dp[i-1][j]+d[i]-d[i-1]);
    }
  }
  long long ans = INF;
  for( int j = 0; j < K; j++ ) {
    ans = min(ans, dp[n-1][j]);
  }
  cout << ans << endl;
}

int main(){
  while(true) {
    if(is_end) break;
    solve();
  }
}