#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
  int NN = 3e5;
  ll mod = 1e9+7;
  vector<ll> fac(NN, 0), finv(NN, 0), inv(NN, 0);

  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i=2;i<NN;i++){
    fac[i] = fac[i-1]*i%mod;
    inv[i] = mod-inv[mod%i]*(mod/i)%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }

  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  for(int i=0;i<min(N, K+1);i++){
    //ans += nCi * N-iHi
    ans += fac[N]%mod*finv[i]%mod*finv[N-i]%mod*fac[N-1]%mod*finv[i]%mod*finv[N-i-1]%mod;
    ans %= mod;
  }
  cout << ans << endl;
}