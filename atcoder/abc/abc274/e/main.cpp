#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double INF = 1e18;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> X(N+M+1), Y(N+M+1); 
  X[0] = 0;
  Y[0] = 0;
  for(int i=1;i<N+M+1;i++){
    cin >> X[i] >> Y[i]; 
  }
  vector<vector<double>> dp(1<<(N+M+1), vector<double>(N+M+1, INF));


  auto dist=[&](int i, int j){
    return hypot(X[i]-X[j], Y[i]-Y[j]);
  };
  dp[1][0] = 0.0;
  for(int i=1;i<1<<(N+M+1);i++){
    int speed = 1<<__builtin_popcount(i>>(N+1));
    for(int j=0;j<(N+M+1);j++){
      if(i&(1<<j)){
        for(int k=0;k<N+M+1;k++){
          if(!(i&1<<k)) dp[i|(1<<k)][k] = min(dp[i|1<<k][k], dp[i][j]+dist(j, k)/speed);
        }
      }
    }
  } 
  double ans = INF;
  int vis = 0;
  for(int i=1;i<N+1;i++){
    vis |= 1<<i;
  }
  for(int i=1;i<N+M+1;i++){
    for(int j=1;j<(1<<(N+M+1));j++){
      int speed = 1<<__builtin_popcount(j>>(N+1));
      if((vis&j)==vis){
        ans = min(ans, dp[j][i]+dist(0, i)/speed);
      }
    }
  }
  cout << fixed << setprecision(16) << ans << endl;
}