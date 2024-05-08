#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 998244353;
vector<ll> fac, finv, inv;


void bino_init(ll N){
  fac.resize(N);
  finv.resize(N);
  inv.resize(N);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<N; i++){
    fac[i] = fac[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll comb(ll n, ll r){
  if(r>n||n<0||r<0) return 0;
  return fac[n]*finv[r]%mod*finv[n-r]%mod;
}


int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<ll>> dp(27, vector<ll>(N+1));
  dp[0][0] = 1;
  bino_init(5050);
  vector<int> count(26);
  for(auto s: S) count[s-'a']++;
  for(int i=0;i<26;i++){
    for(int j=0;j<N+1;j++){
      for(int k=0;k<1+count[i];k++){
        if(j-k<0) break;
        dp[i+1][j] += dp[i][j-k] * comb(j, k);
        dp[i+1][j] %= mod;
      }
    }
  }

  ll ans = 0;
  for(int i=1;i<N+1;i++){
    ans += dp[26][i];
    ans %= mod;
  }
  cout << ans << endl;
}