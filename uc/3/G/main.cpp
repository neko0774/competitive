#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void solve(vector<vector<int>> &G, int &N, int &M){
  vector<int> ret;
  vector<bool> seen(N);
  ret.push_back(0);
  for(int i=0;i<N;i++){
    vector<int> nxt;
    for(auto nx: &G[x]){
      if(!seen[nx]) nxt.push_back(nx);
    }
    if(nxt.size()==0)return;
    int nx = rand()%nxt.size();
    ret.push_back(nx);
  }
  ans.push_back(ret);
}

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> G(N, vector<int>());
  int u, v;
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  while(ans.size()<K){
    solve(&G);
  }
  for(auto a: ans){
    for(auto aa: a) cout << a+1 << ' ';
  }
}