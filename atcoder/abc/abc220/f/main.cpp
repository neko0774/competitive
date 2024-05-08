#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  int u, v;
  cin >> N;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<N;i++){
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<int> dp(N  );
}