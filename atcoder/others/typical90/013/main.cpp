#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
  int to;
  ll cost;
};

const ll INF = 1e18;
template<typename T, typename U>
vector<T> dijkstra(vector<vector<edge>> G, U s, T a){
  U N = G.size();
  vector<T> dist(N, INF);
  dist[s] = 0;
  priority_queue<pair<T, U>, vector<pair<T, U>>, greater<pair<T, U>>> q;
  q.emplace(0, s);
  while(!q.empty()){
    auto [d, x] = q.top();q.pop();
    if(d>dist[x]) continue;
    for(auto [nx, cost] : G[x]){
      if(d+cost<dist[nx]){
        dist[nx] = cost+d;
        q.emplace(dist[nx], nx);
      }
    }
  }
  return dist;
}


int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<edge>> G(N, vector<edge>());
  for(int i=0;i<M;i++){
    int A, B;
    ll C;
    cin >> A >> B >> C;
    A--;
    B--;
    G[B].push_back({A, C});
    G[A].push_back({B, C});
  }
  auto start = dijkstra(G, 0, 0ll);
  auto end = dijkstra(G, N-1, 0ll);
  for(int k=0;k<N;k++){
    cout << start[k]+end[k] << endl;
  }
}