#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct dsu{
  int N, group_size;
  vector<int> root, size;
  dsu(int _N=0): root(_N), size(_N){
  for(int i=0;i<_N;i++){
    root[i]=i;
  }
  N = _N;
  group_size = _N;
  }

  int merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return -1;
    if (size[y]>size[x]) swap(x, y);
    root[y] = root[x];
    size[y] += size[x];
    group_size--;
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

  vector<vector<int>> groups(){
    vector<vector<int>> keep(N, vector<int>());
    vector<vector<int>> ret;
    for(int i=0;i<N;i++){
      keep[find(i)].push_back(i);
    }
    for(int i=0;i<N;i++){
      if(keep[i].size()!=0){
        ret.push_back(keep[i]);
      }
    }
    return ret;
  }
};

int main(){
  int N, Q;
  cin >> N >> Q;
  dsu uf(N+1);
  int l, r;
  for(int i=0;i<Q;i++){
    cin >> l >> r;
    l--;
    uf.merge(l, r);
  }
  cout << (uf.same(0, N)==1?"Yes":"No") << endl;
}