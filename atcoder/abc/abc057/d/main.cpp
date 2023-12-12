#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> V(N);
  for(int i=0;i<N;i++){
    cin >> V[i];
  }
  ll ans = 0;
  sort(V.rbegin(), V.rend());
  for(int i=0;i<A;i++){
    ans += V[i];
  }
  ll M = N;
  for(int i=0;i<N;i++){
    if(V[i]<V[A-1]){
      M = i;
      break;
    }
  }
  long double vv = (long double)ans/(long double)A;
  vector<vector<unordered_map<ll, ll>>> dp(M+1, vector<unordered_map<ll, ll>>(B+1));
  dp[0][0][0] = 1;
  for(int i=0;i<M;i++){
    for(int j=0;j<B+1;j++){
      for(auto [value, count]:dp[i][j]){
        if(j+1<=B&&V[i]>=V[A-1])dp[i+1][j+1][value+V[i]] += count;
        dp[i+1][j][value] += count;
      }
    }
  }
  ans = 0;
  for(int i=A;i<B+1;i++){
    for(auto [value, count]:dp[M][i]){
      if((long double)value/(long double)i==vv) ans += count;
    }
  }
  cout << vv << endl;
  cout << ans << endl;
}