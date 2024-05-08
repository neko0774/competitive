#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int par, vector<vector<int>> &G, int Y, vector<int> &ans){
  ans.push_back(x+1);
  if(x==Y-1){
    for(auto a: ans)cout << a << ' ';
    return;
  }
  for(auto nx: G[x]){
    if(nx!=par){
      dfs(nx, x, G, Y, ans);
    }
  }
  ans.pop_back();
}



int main(){
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<vector<int>> G(N, vector<int>());
  int u, v;
  for(int i=0;i<N-1;i++){
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> ans;
  dfs(X-1, -1, G, Y, ans);
}