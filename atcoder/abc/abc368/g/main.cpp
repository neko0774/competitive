#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/segtree>


ll op(ll a, ll b){
  return a + b;
}

ll e() {
  return 0ll;
}


int main(){
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
  }

  atcoder::segtree<ll, op, e> sg(A);
  set<ll> comp;
  comp.insert(N);
  for(int i=0;i<N;i++){
    if(B[i] >= 2)comp.insert(i);
  }
  int Q; cin >> Q;
  int q, l, r;
  for(auto x: comp) cout << x << ' ';
  cout << endl;
  for(int i=0;i<Q;i++){
    cout << i << endl;
    cin >> q >> l >> r;
    l--;
    if(q == 1){
      sg.set(l, r);
    }else if(q == 2){
      if(B[l] >= 2) comp.erase(l);
      B[l] = r;
      if(r >= 2) comp.insert(l);
    }else{
      ll v = 0;
      v += A[l];
      l++;
      cout << 1 << ' ' << l << ' ' << r << endl;
      while(l < r){
        int nxt = *comp.lower_bound(l);
        cout << l << ' ' << r << ' ' << nxt << endl;
        v += sg.prod(l, nxt);
        if(v + A[nxt] > v * B[nxt]){
          v += A[nxt];
        }else{
          v *= B[nxt];
        }
        l = nxt;
      }
    }
  } 
}