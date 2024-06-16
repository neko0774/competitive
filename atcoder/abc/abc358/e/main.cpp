#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint998244353;

vector<mint> fac, finv, inv;

void bino_init(int N) {
    fac.resize(N + 1);
    finv.resize(N + 1);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = fac[i - 1] * i;
        finv[i] = finv[i - 1] / i;
    }
}

mint comb(int n, int r){
  if(r>n||n<0||r<0) return 0;
  return fac[n]*finv[r]*finv[n-r];
}

int main(){
  int K;
  cin >> K;
  vector<int> C(26);
  for(int i=0;i<26;i++){
    cin >> C[i];
  }
  mint ans = 0;
  vector<vector<mint>> dp(27, vector<mint>(K+1, 0));
  bino_init(2000);
  dp[0][0] = 1;
  for(int i=0;i<26;i++){
    for(int j=0;j<=K;j++){
      for(int k=0;k<=min(C[i], j);k++){
        //if(j==1) cout << k << ' ' << dp[i-1][j-k].val() << ' ' << mint(comb(j+k, k)).val() << endl;
        dp[i+1][j] += dp[i][j-k] * comb(j, j-k);
      }
      //cout << dp[i][j].val() << ' ';
    }
    //cout << endl;
  }
  for(int i=1;i<=K;i++){
    ans += dp[26][i];
  }
  cout << ans.val() << endl;
}