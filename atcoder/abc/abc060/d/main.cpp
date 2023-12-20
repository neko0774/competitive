#include <bits/stdc++.h>
using namespace std;
#define ll long long

void show(vector<vector<ll>> A){
  for(auto AA:A){
    for(auto a:AA)cout << a << ' ';
    cout << endl;
  }
}

int main(){
  int N;
  ll W;
  cin >> N >> W;
  vector<ll> weight(N), value(N);
  for(int i=0;i<N;i++){
    cin >> weight[i] >> value[i];
  }
  ll buffer = weight[0];
  for(int i=0;i<N;i++){
    weight[i] -= buffer;
  }
  vector<vector<ll>> dp(3*N+1, vector<ll>(1+N, 0));
  for(int i=0;i<N;i++){
    for(int j=3*N;j>=0;j--){
      for(int k=N;k>0;k--){
        if(j-weight[i]>=0&&k-1>=0) dp[j][k] = max(dp[j-weight[i]][k-1]+value[i], dp[j][k]);
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<3*N+1;i++){
    for(int k=1;k<N+1;k++){
      if(i+buffer*k<=W) ans = max(ans, dp[i][k]);
    }
  }
  //show(dp);
  cout << ans << endl;
}
