#include<bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>

int main(){
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  int u, v;
  for(int i=0;i<N;i++){
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> ans(N);
  ans[N - 1] = N;
  atcoder::dsu uf(N);
  for(int i = N - 1;i >= 1; i--){
    ans[i]
  }
}