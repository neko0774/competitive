#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 988244353;



int main(){
  int N, M;
  cin >> N >> M;
  int u,v;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
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
}