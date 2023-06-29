#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> scc(vector<vector<int>> G) {
  int N = G.size();
  vector<vector<int>> I(N, vector<int>());
  for( int i = 0; i < N; i++ ) {
    for( int v : G[i] ) {
      I[v].push_back(i);
    }
  }
  vector<int> vs;
  vector<bool> vis(N);
  auto dfs = [&](auto dfs, int cur) -> void {
    vis[cur] = true;
    for( int nxt : G[cur] ) {
      if( !vis[nxt] ) dfs(dfs, nxt);
    }
    vs.push_back(cur);
  };
  auto dfs2 = [&](auto dfs2, int cur, vector<int> &ret) -> void {
    vis[cur] = true;
    ret.push_back(cur);
    for( int nxt : I[cur] ) {
      if( !vis[nxt] ) dfs2(dfs2, nxt, ret);
    }
  };
  fill(vis.begin(), vis.end(), false);
  for( int i = 0; i < N; i++ ) {
    if( !vis[i] ) dfs(dfs, i);
  }
  fill(vis.begin(), vis.end(), false);
  int k = 0;
  vector<vector<int>> ret;
  for( int i = vs.size()-1; i >= 0; i-- ) {
    if( !vis[vs[i]] ) {
      vector<int> ret_sub;
      dfs2(dfs2, vs[i], ret_sub);
      ret.push_back(ret_sub);
    }
  }
  return ret;
}
bool solve() {
  int N;
  cin >> N;
  if( N == 0 ) return false;
  vector<double> p(N);
  vector<vector<int>> G(N, vector<int>());
  for( int i = 0; i < N; i++ ) {
    int m;
    cin >> p[i] >> m;
    for( int j = 0; j < m; j++ ) {
      int a;
      cin >> a;
      G[i].push_back(--a);
    }
  }
  vector<vector<int>> s = scc(G);
  vector<int> group(N), deg(N);
  for( int i = 0; i < s.size(); i++ ) {
    for( int v : s[i] ) group[v] = i;
  }
  for( int i = 0; i < N; i++ ) {
    for( int v : G[i] ) {
      if( group[i] != group[v] ) deg[v]++;
    }
  }
  double ans = 1;
  for( int i = 0; i < s.size(); i++ ) {
    int deg_sum = 0;
    double p_prod = 1;
    for( int v : s[i] ) deg_sum += deg[v], p_prod *= p[v];
    if( deg_sum == 0 ) ans *= 1.0-p_prod;
  }
  cout << fixed << setprecision(10) << ans << endl;
  return true;
}
int main(){
  while( solve() == true ) {}
}

