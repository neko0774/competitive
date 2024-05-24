#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> dp;

int main(){
  ll N, M;
  cin >> N >> M;
  ll A, B;
  vector<ll> G(N, 0);
  dp.resize(1<<N, N);
  dp[0] = 1;
  for(int i=0;i<M;i++){
    cin >> A >> B;
    A--;B--;
    G[A] |= 1<<B;
    G[B] |= 1<<A;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<(1<<N);j++){
      if(dp[j]==1&&(G[i]&j)==j){
        dp[j|(1<<i)] = 1;
      }
    }
  }
  for(ll S=0;S<(1<<N);S++){
    for(ll T=S;T>0;T=(T-1)&S){
      dp[S] = min(dp[S], dp[S^T]+dp[T]);
    }
  }
  cout << dp[(1<<N) - 1] << endl;
}