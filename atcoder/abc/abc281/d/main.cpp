#include<bits/stdc++.h>
using namespace std;
#define ll long long


void show(vector<vector<ll>> A){
  for(int i=0;i<A.size();i++){
    for(auto a: A[i]) cout << a << ' ';
    cout << endl;
  }
}


void chmax(ll &a, ll b){
  if(b>a) a = b;
}

int main(){
  int N, K, D;
  cin >> N >> K >> D;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(D, vector<ll>(K+1, -1)));
  dp[0][0][0] = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
      for(int k=0;k<1+K;k++){
        if(k>0&&dp[i][(D+j-A[i]%D)%D][k-1]!=-1)chmax(dp[i+1][j][k], dp[i][(D+j-A[i]%D)%D][k-1]+A[i]);
        chmax(dp[i+1][j][k], dp[i][j][k]);
      }
    }
    //show(dp[i+1]);
    //cout << endl;
  }
  cout << dp[N][0][K] << endl;
}