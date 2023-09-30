#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void show(vector<vector<int>> G){
  for(auto a: G){
    for(auto x: a) cout << x << ' ';
    cout << endl;
  }
}


pair<int, int> bfs(vector<vector<int>> &G, int s){
  int N = G.size();
  vector<int> dist(N, -1);
  queue<int> q;
  q.push(s);
  dist[s]=0;
  int lx;
  while(!q.empty()){
    int x = q.front();q.pop();
    for(auto nx: G[x]){
      if(dist[nx]==-1){
        q.emplace(nx);
        dist[nx] = dist[x]+1;
        if(dist[nx]>dist[lx]) lx = nx;
      }
    }
  }
  return make_pair(lx, dist[lx]);
}

int main(){
  int N;
  cin >> N;
  vector<vector<int>> G(N, vector<int>());
  
  for(int i=0;i<N-1;i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  pair<int, int> d = bfs(G, 0);
  pair<int, int> s = bfs(G, d.first);
  cout << s.second+1 << endl;
}