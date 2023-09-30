#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
  ll to;ll d;
};
void show(unordered_set<ll> vis){
  for(auto x: vis) cout << x << ' ';
  cout << endl;
}


void dfs(ll &ans, vector<vector<edge>> &G, unordered_set<ll> visited, vector<bool> &seen, ll x, ll dist){
  ans = max(ans, dist);
  cout << ans << ' ' << x << endl;
  show(visited);
  seen[x] = true;
  for(auto nx: G[x]){
    if(visited.count(nx.to)==0){
      visited.insert(nx.to);
      dist += nx.d;
      dfs(ans, G, visited, seen, x, dist);
      visited.erase(nx.to);
    }
  }
  visited.erase(x);
}

int main(){
  ll N, M;
  cin >> N >> M;
  vector<vector<edge>> G(N, vector<edge>());
  ll A, B, C;
  for(int i=0;i<M;i++){
    cin >> A >> B >> C;
    A--;B--;
    G[A].push_back({B, C});
    G[B].push_back({A, C});
  }
  ll ans = 0;
  vector<bool> seen(N, false);
  for(int i=0;i<N;i++){
    unordered_set<ll> visited;
    visited.insert(i);
    cout << i << endl;
    dfs(ans, G, visited, seen, 0, 0);
  }
  cout << ans << endl;
}