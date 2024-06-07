#include <bits/stdc++.h>
using namespace std;
vector<int> G[1<<18];
vector<pair<int, int>> ans1, ans2;
vector<bool> vis1, vis2;


void dfs(int x, int par){
  vis1[x] = 1;
  for(auto nx:G[x]){
    if(vis1[nx]||par==nx) continue;
    ans1.push_back(make_pair(x, nx));
    dfs(nx, x);
  }
}


int main(){
  int N, M;
  cin >> N >> M;
  vis1.resize(N);
  vis2.resize(N);
  int u, v;
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  queue<pair<int, int>> q;
  q.push(make_pair(0, -1));

  vis2[0] = 1;
  while(!q.empty()){
    auto [x, par] = q.front();
    q.pop();
    for(auto nx: G[x]){
      if(nx==par||vis2[nx])continue;
      q.push(make_pair(nx, x));
      vis2[nx]=1;
      ans2.push_back(make_pair(x, nx));
    }
  }
  for(auto [u, v]: ans1) cout << u+1 << ' ' << v+1 << endl;
  for(auto [u, v]: ans2) cout << u+1 << ' ' << v+1 << endl;
}