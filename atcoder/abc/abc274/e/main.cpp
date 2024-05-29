#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long double INF = 1e18;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> X(N+M+1), Y(N+M+1); 
  X[0] = 0;
  Y[0] = 0;
  for(int i=1;i<N+M;i++){
    cin >> X[i] >> Y[i]; 
  }
  vector<vector<double>> dp(N+M+1, vector<double>(N+1, INF));


  auto dist=[&](int i, int j){
    return sqrt((double)(X[i]-X[j])*(X[i]-X[j])+ (double)(Y[i]-Y[j])*(Y[i]-Y[j]));
  };
  dp[1][0] = 0.0;
  int tres=0;
  for(int i=N+1;i<N+M+1;i++){
    tres |= 1<<i; 
  }
  for(int i=0;i<1<<(N+M+1);i++){
    int speed = __popcount(i&tres);
    for(int j=0;j<(N+M+1);j++){
      if(i&(1<<j)){
        for(int k=0;k<N+M;k++){
          dp[i|(1<<j)][k] = min(dp[1|1<<j][k], dp[i][j]+dist(j, k)/speed);
        }
      }
    }
  } 
}