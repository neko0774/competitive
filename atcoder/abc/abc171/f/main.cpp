#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
const ll mod = 1e9+7;

vector<ll> fac, finv, inv;
void bino_init(int N){
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

template<typename T>
T mod_pow(T x, T power, T mod=mod){
  T ret = 1;
  while(power){
    if(power&1)ret *= x, ret%=mod;
    x *= x;
    x %= mod;
    power>>=1;
  }
  return ret;
}

int main(){
  int K;
  cin >> K;
  string S;
  cin >> S;
  int N = S.length();
  ll ans = 0;
  bino_init(N+K+5);
  for(int k=0;k<=K;k++){
    ans += mod_pow(26LL, (ll)k)*mod_pow(25LL, (ll)(K-k))%mod*comb((ll)(K-k+N-1), (ll)(N-1))%mod;
    ans %= mod;
  }
  cout << ans << endl;
}