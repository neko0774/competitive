#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

ll combination(ll a, ll b, vector<ll> &fac, vector<ll> &finv){
  if (a<b||a<0||b<0) return 0;
  return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

int main(){
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  int N = 2*max(H, W)+5;
  vector<ll> fac(N, 0);
  vector<ll> finv(N, 0);
  vector<ll> inv(N, 0);
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2;i<N;i++){
    fac[i] = fac[i-1]*i%mod;
    inv[i] = mod-inv[mod%i]*(mod/i)%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
  ll ans = 0;
  for(ll i=0;i<H-A;i++){
    ans += combination(B-1+i, i, fac, finv)*combination(W-B-1+H-i-1, W-B-1, fac, finv)%mod;
    ans %= mod;
  }
  cout << ans << endl;  
}