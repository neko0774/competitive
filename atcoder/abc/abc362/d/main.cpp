#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

vector<ll> dijkstra(int s, vector<vector<pair<int, ll>>> &G, vector<ll> &A){
  int node = G.size();
  vector<ll> cost(node, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> hq;
  vector<bool> seen(N, false);
  cost[s] = A[s];
  hq.push({0, s});
  while(!hq.empty()){
    int v = hq.top().second();
    seen[v] = true;
    while hq:
    v = 
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<vector<pair<int, ll>>> G(N, vector<pair<int, ll>>());
  int u, v;
  ll b;
  for(int i=0;i<M;i++){
    cin >> u >> v >> b;
    u--;
    v--;
    G[u].push_back(make_pair(v, b));
    G[v].push_back(make_pair(u, b));
  }
}