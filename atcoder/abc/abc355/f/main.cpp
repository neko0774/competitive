#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
  int N, Q;
  cin >> N >> Q;
  vector<dsu> S(10, dsu(N));
  int cur = N-1;
  dsu uf(N);
  int u, v, c;
  vector<tuple<int, int, int>> G;
  for(int i=0;i<N-1;i++){
    cin >> u >> v >> c;
    u--;v--;c--;
    for(int j=9;j>=c;j--){
      S[j].merge(u, v);
    }
    G.push_back(make_tuple(c, u, v));
  }
  sort(G.begin(), G.end());
  for(auto [c, u, v]: G){
    if(!uf.same(u, v)){
      cur += c;
      uf.merge(u, v);
    }
  }
  for(int i=0;i<Q;i++){
    cin >> u >> v >> c;
    u--;v--;c--;
    bool seen = false;
    int cost = 10;
    for(int i=0;i<10;i++){
      if(S[i].same(u, v)){
        cost = i;
        break;
      }
    }
    if(c<cost) cur += c-cost;
    for(int j=9;j>=c;j--){
      S[j].merge(u, v);
    }
    cout << cur << endl;
  }
}