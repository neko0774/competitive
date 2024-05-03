#include <bits/stdc++.h>
using namespace std;
#define ll long long
<<<<<<< HEAD
const ll mod = 998244353;

struct dsu{
  int N;
  vector<int> root, size;
  dsu(int _N=0): root(_N), size(_N){
  N = _N;
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
=======
const ll mod = 988244353;
>>>>>>> c5514de29cdd71ff6e53569b5be7815f238496bb



int main(){
  int N, M;
  cin >> N >> M;
  int u,v;
  vector<vector<int>> G(N, vector<int>());
<<<<<<< HEAD
  dsu uf(N);
=======
>>>>>>> c5514de29cdd71ff6e53569b5be7815f238496bb
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
<<<<<<< HEAD
    uf.merge(u, v);
  }
  int cnt = 0;
  for(auto g:uf.groups()){
    int vertex = g.size(), edges = 0;
    for(int x: g){
      edges += G[x].size();
    }
    if(edges/2!=vertex){
      cout << 0 << endl;
      return 0;
    }
    cnt++;
  }
  int ans = 1;
  for(int i=0;i<cnt;i++){
    ans *= 2;
    ans %= mod;
  }
  cout << ans << endl;
=======
  }
  int cnt = 0;
  vector<bool> seen(N, false);
  bool ok = true;
  for(int i=0;i<N;i++){
    if(seen[i]) continue;
    queue<pair<int, int>> q;
    seen[i] = true;
    cnt++;
    bool exist_cycle = false;
    int edge = 0, vertex = 1;
    q.push(make_pair(i, -1));
    while(!q.empty()){
      auto [x, lx] = q.front();q.pop();
      edge += G[x].size();
      for(auto nx:G[x]){
        if(nx==lx){continue;}
        else if(seen[nx]){
          exist_cycle = true;
        }else{
          vertex++;
          seen[nx] = true;
          q.push(make_pair(nx, x));
        }
      }
    }
    if(!exist_cycle||edge/2!=vertex)ok=false;
  }
  ll ans = 1;
  if(ok){
    for(int i=0;i<cnt;i++){
      ans *= 2;
      ans %= mod;
    }
    cout << ans << endl;
  }else{
    cout << 0 << endl;
  }
>>>>>>> c5514de29cdd71ff6e53569b5be7815f238496bb
}