#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll sq(ll x) {
  return x * x;
}

ll isqrt(ll x) {
  ll ok = 0, ng = x + 1;
  while(ok + 1 < ng) {
    ll s = (ok + ng) / 2;
    if(s * s <= x) ok = s;
    else ng = s;
  }
  return ok;
}

ll count123(const ll L) {
  ll ret = 0;
  for(ll x = -L; x < 0; x++) {
    ll ok = 0, ng = L + 1;
    while(ok + 1 < ng) {
      ll y = (ok + ng) / 2;
      if(x * x + y * y <= L * L) ok = y;
      else ng = y;
    }
    ret += ok;
  }
  return ret;
}

ll count4(ll W, ll H, ll L) {
  if (L <= H) return 0;
  ll ret = 0;
  for(ll x = 1; x < W; x++) {
    const ll lim = max(sq(L - H) - sq(x), sq(L - H - W) - sq(x - W));
    if(H * H > lim) continue;
    ll ok = H, ng = L + 1;
    while(ok + 1 < ng) {
      ll y = (ok + ng) / 2;
      if(y * y <= lim) ok = y;
      else ng = y;
    }
    ret += ok;
  }
  return ret;
}

ll count5(ll W, ll H, ll L) {
  if (L <= W) return 0;
  ll ret = 0;
  for(ll y = 1; y < H; y++) {
    const ll lim = max(sq(L - W) - sq(y), sq(L - H - W) - sq(y - H));
    if(1 > lim) continue;
    ll ok = 1, ng = L + 1;
    while(ok + 1 < ng) {
      ll x = (ok + ng) / 2;
      if(x * x <= lim) ok = x;
      else ng = x;
    }
    ret += ok;
  }
  return ret;
}

ll count6(ll H, ll W, ll L) {
  if (L <= H + W) return 0;
  ll ret = 0;
  for(ll x = W + 1; x <= L; x++) {
    if(sq(L - H) - sq(x) < 0) continue;
    if(sq(L - W) - sq(x - W) < 0) continue;
    ll lim = max(isqrt(sq(L - H) - sq(x)) + H, isqrt(sq(L - W) - sq(x - W)));
    if (lim < H) continue;
    ret += lim - H;
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll W, H, L;
  cin >> W >> H >> L;
  ll ans = 0;
  ans += 3 * count123(L);
  cout << ans << endl;
  ans += count4(W,H,L);
  cout << ans << endl;
  ans += count5(W,H,L);
  cout << ans << endl;
  ans += count6(W,H,L);
  cout << ans << endl;
  ans += 2 * L + 2 * max(ll(0), L - H - W) + max(ll(0), L - 2 * H - W) + max(ll(0), L - 2 * W - H);
  cout << ans << endl;
}