#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<typename Monoid>
struct segtree{
  using F = function< Monoid(Monoid, Monoid) >;
  int size;
  const Monoid e;
  const F op;
  vector<Monoid> seg;
  segtree(int _N, F _op, const Monoid &_e): op(_op), e(_e){
    size = 1;
    while(size<_N) size <<= 1;
    seg.assign(2*size, e);
  }

  Monoid fold(int l, int r){
    Monoid vl = e, vr = e;
    for(l += size, r += size; l < r; l >>= 1, r >>= 1){
      if(l&1)vl = op(vl, seg[l++]);
      if(r&1)vr = op(vr, seg[--r]);
    }
    return op(vl, vr);
  }

  void set(int i, Monoid x){
    i += size;
    seg[i] = op(x, seg[i]);
    while(i>>=1){
      seg[i] = op(seg[i*2], seg[i*2+1]);
    }
  }

  Monoid get(int i){
    return seg[i+size];
  }

  void debug(){
    for(int i=0;i<size;i++){
      cout << seg[i+size] << ' ';
    }
    cout << endl;
  }
};

const ll INF = 1e18;
int main(){
  int N;
  ll C;
  cin >> N >> C;
  int M;
  cin >> M;
  ll T, P;
  segtree<ll> seg1(N, [](ll a, ll b){return max(a, b);}, -INF);
  segtree<ll> seg2(N, [](ll a, ll b){return max(a, b);}, -INF);
  seg1.set(0, 0);
  seg2.set(0, 0);
  ll l, r, v;

  for(int i=0;i<M;i++){
    cin >> T >> P;
    T--;
    l = seg1.fold(T, N) + C*T + P;
    r = seg2.fold(0, T) - C*T + P;
    v = max(l, r);
    seg1.set(T, v - C*T);
    seg2.set(T, v + C*T);
  }

  ll ans = 0;
  for(int i=0;i<N;i++){
    ans = max(ans, seg1.get(i) + i*C);
  }
  cout << ans << endl;
}