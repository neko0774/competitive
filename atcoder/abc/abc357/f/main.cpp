#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include<atcoder/all>
const ll mod = 998244353;
using mint = atcoder::modint998244353;
using S = vector<mint>;
using F = vector<mint>;

S op(S a, S b){return {a[0]+b[0], (a[1]+b[1]), (a[2]+b[2]), (a[3]+b[3])};}
S e(){return {0, 0, 0, 0};}
S mapping(F f, S x){return {x[0], (x[1]+f[0]*x[0]), (x[2]+f[1]*x[0]), (((x[3]+f[0]*x[2])+f[1]*x[1])+f[0]*f[1]*x[0])};}
F composition(F f, F g){return {(g[0]+f[0]), (g[1]+f[1])};}
F id(){return {0, 0};}
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N), B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  vector<vector<mint>> data(N);
  for(int i=0;i<N;i++){
    data[i] = {1, mint(A[i]), mint(B[i]), mint(A[i])*mint(B[i])};
  }
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> lazyseg(data);
  for(int i=0;i<Q;i++){
    int q;
    cin >> q;
    if(q==1){
      int l, r, x;
      cin >> l >> r >> x;
      lazyseg.apply(l-1, r, {mint(x), mint(0)});
    }else if(q==2){
      int l, r, x;
      cin >> l >> r >> x;
      lazyseg.apply(l-1, r, {mint(0), mint(x)});
    }else{
      int l,r;
      cin >> l >> r;
      cout << lazyseg.prod(l-1, r)[3].val() << endl;
    }
  }
}