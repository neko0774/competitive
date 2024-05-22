#include<bits/stdc++.h>
using namespace std;
struct dsu{
  int N;
  vector<int> root, size;
    dsu(int _N=0): root(_N), size(_N){
    for(int i=0;i<_N;i++){
      root[i]=i;
    }
    N = _N;
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
  int N, M;
  cin >> N >> M;
  int u, v;
  dsu uf(N);
  vector<int> P(N);
  int p;
  for(int i=0;i<N;i++){
    cin >> p;
    P[p] = i;
  }
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;
    v--;
    uf.merge(u, v); 
  }

  vector<int> V;
  int ans = 0;
  for(auto g: uf.groups()){
    V.clear();
    unordered_set<int> pos;
    for(auto x: g){
      V.push_back(x);
      pos.insert(x);
    }
    for(auto v: V) ans += pos.count(v);
  }
  cout << ans << endl;
}