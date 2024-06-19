#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF=1e18;


ll find(ll D, ll t){
  ll ret = INF;
  ll d = (ll)(sqrt((double)D))-1LL;
  ll cur = max(t, d);
  for(ll i=0;i<=3;i++){
    ret = min(ret, D/(cur+i+1LL)+cur+i);
  }
  return ret;
}

int main(){
  int N, M;
  cin >> N >> M;
  ll A, B, C, D;
  vector<vector<vector<ll>>> G(N);
  for(int i=0;i<M;i++){
    cin >> A >> B >> C >> D;
    A--;
    B--;
    G[A].push_back({B, C, D});
    G[B].push_back({A, C, D});
  }
  vector<ll> dist(N, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  dist[0] = 0;
  q.emplace(0, 0);
  while(!q.empty()){
    auto [t, x] = q.top(); q.pop();
    if(dist[x]<t) continue;
    for(vector<ll> g:G[x]){
      ll nx = g[0], c = g[1], d = g[2];
      ll nx_time = c+find(d, t);
      if(dist[nx]<=nx_time) continue;
      dist[nx] = nx_time;
      q.emplace(nx_time, nx);
    }
  }
  cout << (dist[N-1]==INF?-1:dist[N-1]) << endl;
}