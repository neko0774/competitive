#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15;

struct edge{
  ll to;
  ll cost;
};

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
  ll N, M, K;
  cin >> N >> M >> K;
  ll a, b; 
  vector<vector<edge>> G(N+1, vector<edge>());
  for(int i=0;i<M;i++){
    cin >> a >> b;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
  } 
  vector<pair<ll, ll>> sec;
  ll health = 0;
  for(int i=0;i<K;i++){
    cin >> a >> b;
    sec.push_back(make_pair(a, b));
    health = max(health, b);
  }
  for(auto [p, h]: sec){
    G[0].push_back({p, health-h});
    G[p].push_back({0, health-h});
  }
  auto dist = dijkstra(G, 0ll, 1ll);
  vector<ll> ans;
  for(int i=1;i<G.size();i++){
    if(dist[i]<=health) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(auto a: ans)cout << a << ' ';
}
