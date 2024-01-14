#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e+7;

int main(){
  int N;cin >> N;
  vector<ll> A(N);
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
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  
}