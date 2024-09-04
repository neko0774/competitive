#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  ll a, b, c, d, v, t;
  cin >> a >> b >> c >> d >> v >> t;
  if(c > a){
    swap(a, c);
    swap(b, d);
  }
  ll ac_lcm = lcm(a, c);
  ll cnt_per_period = 0;
  for(ll aa = 0; aa < ac_lcm && aa <= t; aa += a){
    if(aa % c == 0){
      cnt_per_period++;
      continue;
    }
    ll lt = aa / c * c;
    ll gt = (aa + c - 1) / c * c;
    if(gt - aa <= v && gt <= t) cnt_per_period++;
    if(aa - lt <= v) cnt_per_period++;
  }
  ll cnt = t / ac_lcm * cnt_per_period;
  for(ll cur = t / ac_lcm * ac_lcm; cur <= t; cur += a){
    if(cur % c == 0){
      cnt++;
      continue;
    }
    ll lt = cur / c * c;
    ll gt = (cur + c - 1) / c * c;
    if(gt - cur <= v && gt <= t) cnt++;
    if(cur - lt <= v && lt >= t / ac_lcm * ac_lcm) cnt++;
  }
  assert(cnt - t / ac_lcm * cnt_per_period <= cnt_per_period);
  
  ll ans = (t / a + 1) * (b - 1) + (t / c + 1) * (d - 1) + cnt;
  cout << ans << endl;
}


int main(){
  int T;
  cin >> T;
  while(T--) solve();
}