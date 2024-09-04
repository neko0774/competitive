#include<bits/stdc++.h>
using namespace std;


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

  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  
}