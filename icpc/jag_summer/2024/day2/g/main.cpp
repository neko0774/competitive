#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll ans = 0;
  {
    ll d = a / 3;
    ans += d;
    a -= 3 * d;
  }
  {
    ll d = min(a, b / 2);
    ans += d;
    a -= d, b -= 2 * d;
  }
  {
    ll d = min(a, c / 2);
    ans += d;
    a -= d, c -= 2 * d;
  }
  cout << ans + (b + c) / 3 << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  while(T--) solve();
}