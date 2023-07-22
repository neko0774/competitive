#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct vec{
  bool first, second, third;
}


int main(){
  int N, M;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<M;i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int S, T;
  cin >> S >> T;
  S--;
  T--;
  vector<tuple<bool, bool, bool>> dist(N, tuple(false, false, false)); 
  dist[S].
}