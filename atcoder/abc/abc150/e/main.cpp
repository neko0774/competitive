#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;


ll pow(ll x, ll y){
  ll ret = 1;
  while(y>0){
    if(y&1) ret = ret*x%mod;
    x = x*x%mod;
    y >>= 1;
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  vector<ll> C(N);
  for(int i=0;i<N;i++){
    cin >> C[i];
  }
  ll rev = pow(2, mod-2);
  cout << rev << endl;
  sort(C.begin(), C.end());
  ll ans = 0;
  for(int i=0;i<N;i++){
    ans += C[i]*(N-i+1)%mod*pow(2ll, (ll)(2*N-1))%mod*rev%mod;
  }
  cout << ans << endl;
}
