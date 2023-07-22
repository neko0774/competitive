#include <bits/stdc++.h>
using namespace std;
struct dsu{
  int N;
  vector<int> root, size;
  dsu(int _N=0): root(_N), size(_N){
  for(int i=0;i<_N;i++){
    root[i]=i;
  }
  }

  int merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return -1;
    if (size[y]>size[x]) swap(x, y);
    root[y] = root[x];
    size[y] += size[x];
    return root[y];
  }

  bool same(int x, int y){
    return find(x)==find(y);
  }

  int find(int x){
    if (root[x]==x) return x;
    root[x] = find(root[x]);
    return root[x];
  }
};

int main(){
  int N, Q;
  cin >> N >> Q;
  dsu uf(N);
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