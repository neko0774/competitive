#include<bits/stdc++.h>
using namespace std;
template<typename S, auto op, auto e>
struct segtree
{
  int n,log,sz;
  vector<S>d;
  void update(int p){d[p]=op(d[2*p],d[2*p+1]);}
  segtree(int m):n(m)
  {
    log=1;
    while((1<<log)<n)log++;
    sz=1<<log;
    d.assign(2*sz,e());
  }
  S get(int p)
  {
    p+=sz;
    return d[p];
  }
  void set(int p, S x)
  {
    p+=sz;
    d[p]=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  int prod(int l, int r)
  {
    l+=sz,r+=sz;
    S pl=e(),pr=e();
    while(l<r)
    {
      if(l&1)pl=op(pl,d[l++]);
      if(r&1)pr=op(d[--r],pr);
      l/=2,r/=2;
    }
    return op(pl,pr);
  }
  S all_prod(){return d[1];}
};

using S = pair<int, int>;
S e() { return S{-1, -1}; }
S op(S x, S y) { return max(x, y); }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> L(Q), R(Q);
  for(int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
    L[i]--, R[i]--;
  }

  const int B = 700;
  const int C = (N + B - 1) / B;
  vector<vector<pair<int, int>>> group(C);
  for(int i = 0; i < Q; i++) {
    group[L[i] / B].push_back(make_pair(R[i], i));
  }
  for(int i = 0; i < C; i++) {
    if(!group[i].empty()) {
      sort(group[i].begin(), group[i].end());
      if(i % 2 == 1) reverse(group[i].begin(), group[i].end());
    }
  }

  vector<int> A2 = A;
  sort(A2.begin(), A2.end());
  A2.erase(unique(A2.begin(), A2.end()), A2.end());
  for(int &a : A) a = lower_bound(A2.begin(), A2.end(), a) - A2.begin();

  const int K = A2.size();
  segtree<S, op, e> seg(K);
  for(int i = 0; i < K; i++) seg.set(i, S{0, i});
  
  auto ins = [&](int v) -> void {
    const S s = seg.get(v);
    seg.set(v, S{s.first + 1, s.second});
  };

  auto del = [&](int v) -> void {
    const S s = seg.get(v);
    seg.set(v, S{s.first - 1, s.second});
  };

  int p = 0, q = 0;
  ins(A[0]);
  vector<int> ans(Q);
  for(const auto &v : group) {
    for(const auto &qry : v) {
      const int i = qry.second;
      const int l = L[i];
      const int r = R[i];
      while(q < r) ins(A[++q]);
      while(p > l) ins(A[--p]);
      while(q > r) del(A[q--]);
      while(p < l) del(A[p++]);
      ans[i] = (seg.all_prod()).second;
    }
  }

  for(int i = 0; i < Q; i++) {
    cout << A2[ans[i]] << "\n";
  }
}