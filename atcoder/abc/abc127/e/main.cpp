#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
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
  ll H, W, K;
  cin >> H >> W >> K;
  bino_init(H*W);
  auto calc = [&](ll N, ll M){
    ll ret = 0;
    for(ll i=1;i<N+1;i++){
      ret += i*(N-i)%mod*M%mod*M*comb(H*W-2, K-2)%mod;
      ret %= mod;
    }
    return ret;
  };
  ll ans = calc(H, W)+calc(W, H);
  cout << ans%mod << endl;
}