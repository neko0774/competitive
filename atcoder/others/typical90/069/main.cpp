#include<iostream>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
template<typename T>

T modpow(T x, T n, T mod){
  T ret=1;
  while(n){
    if(n&1){
      ret *= x;
      ret %= mod;
    }
    n/=2;
    x=x*x;
    x%=mod;
  }
return ret;
}


int main(){
  ll N, K;
  cin >> N >> K;
  if(N==1) cout << K << endl;
  else cout << K*(K-1)%mod*modpow(K-2, N-2, mod)%mod << '\n';
}