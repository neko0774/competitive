#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  ll a, b, c, d, v, t;
  cin >> a >> b >> c >> d >> v >> t;
  if(c > a) swap(a, c), swap(b, d);

  if(v >= c){
    cout << b * (t / a + 1) + d * (t / c + 1) - 1 << endl;
    return;
  }

  ll lcm = a * c / gcd(a, c);
  ll cnt_per_perodic = 0;
  for(ll cur = 0; cur < min(lcm, t); cur += a){
    if(cur % c == 0){
      cnt_per_perodic++;
      continue;
    }
    ll lt = cur / c * c;
    ll gt = (cur + c - 1) / c * c;
    if(gt - cur <= v && gt <= t) cnt_per_perodic++;
    if(cur - lt <= v) cnt_per_perodic++;
  }

  ll cnt = t / lcm * cnt_per_perodic;
  ll rest = t / lcm * lcm;
  for(ll cur = rest; cur <= t; cur += a){
    if(cur % c == 0){
      cnt++;
      continue;
    }
    ll lt = cur / c * c;
    ll gt = (cur + c - 1) / c * c;
    if(gt - cur <= v && gt <= t) cnt++;
    if(cur - lt <= v && rest <= lt) cnt++;
  }

  ll ans = (t / a + 1) * (b - 1) + (t / c + 1) * (d - 1) + cnt;
  cout << ans << endl;
}

int main(){
  int T;
  cin >> T;
  while(T--) solve();
}