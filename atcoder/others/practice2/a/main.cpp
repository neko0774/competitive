#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;
  atcoder::dsu uf(N);
  for(int i=0;i<Q;i++){
    int t, u, v;
    cin >> t >> u >> v;
    if(t==0){
      uf.merge(u, v);
    }
    else{
      if(uf.same(u, v)){cout << 1 << endl;}
      else{cout << 0 << endl;}
    }
  }
}