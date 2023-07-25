#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int INF=1e9;


void show(deque<int> q){
  for(auto i:q) cout << i;
  cout << endl;
}

void dfs(vector<int> &list, int x, int cnt){}


int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<M;i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<vector<int>> nG(N, vector<int>());
  for(int i=0;i<N;i++){
    deque<pair<int, int>> q;
    q.push_back(make_pair(i, 0));
    dfs(&nG[i], i, 0);
  }



  int S, T;
  cin >> S >> T;
  S--;
  T--;
  vector<int> dist(N, INF); 
  dist[S] = 0;
  deque<int> q;
  q.push_back(S);
  show(q);
  while(!q.empty()){
    int x = q[0];
    q.pop_front();
    for(auto nx: nG[x]){
      if(dist[nx]>dist[x]+1){
        dist[nx] = dist[x]+1;
        q.push_back(nx);
      }
      }
    }
  }
  if(dist[T]!=INF) cout << dist[T] << '\n';
  else cout << -1 << '\n';
}