#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  ll N, M;
  cin >> N >> M;

  ll l = max(1LL, N-M);
  ll r = N+M;
  ll ans = N;

  ll bit = 31;
  for(ll i=0;i<bit;i++){
    ll ls = N%(1<<i);
    ll nx = (1<<i)-ls;
    if(N+nx<=r) ans |= (1<<i);
    if(l<=N-ls&&N>=(1<<i)) ans |= (1<<i);
  }
  cout << ans << endl;
}

int main(){
  int T;
  cin  >> T;
  while(T--) solve();
}