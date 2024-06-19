#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint1000000007;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<ll> B(N+1);
  for(int i=0;i<N;i++){
    B[i+1] += B[i] + A[i];
  }
  vector<vector<mint>> cnt(N+1, vector<mint>(N+1));
  vector<mint> dp(N+1);
  cnt[1][0] = 1;
  for(int i=1;i<N+1;i++){
    dp = vector<mint>(N+1);
    for(int j=1;j<=N;j++){
      dp[j] += cnt[j][B[i]%j];
    }
    for(int j=2;j<=N;j++){
      cnt[j][B[i]%j] += dp[j-1];
    }
  }
  mint ans;
  for(int i=1;i<=N;i++){
    ans += dp[i];
  } 
  cout << ans.val() << endl;
}