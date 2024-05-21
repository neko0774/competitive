#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> cnt, ans;
void dfs(int x, int par, vector<vector<int>> &G){
  cnt[x] += 1;
  for(auto nx: G[x]){
    if(nx!=par){
      dfs(nx, x, G);
      cnt[x] += cnt[nx];
      ans[x] += ans[nx] + cnt[nx];
    }
  }
}

void dfs2(int x, int par, vector<vector<int>> &G, int N){
  if(par!=-1) ans[x] = ans[par] + N-2*cnt[x];
  for(auto nx: G[x]){
    if(nx!=par) dfs2(nx, x, G, N);
  }
}

int main(){
  int N;
  int u, v;
  cin >> N;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<N-1;i++){
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cnt.resize(N);
  ans.resize(N);

  dfs(0, -1, G);
  dfs2(0, -1, G, N);
  for(auto a: ans) cout << a << endl;
}