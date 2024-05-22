#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> G[1<<17];

void dfs(int x, vector<bool> &seen, vector<vector<int>> &G, vector<int> &vis){
  seen[x] = true;
  for(auto &nx: G[x]){
    if(!seen[nx]) dfs(nx, seen, G, vis);
  }
  vis.push_back(x);
}

void rdfs(int x, vector<bool> &seen, vector<vector<int>> &rG, vector<int> &groups){
  groups.push_back(x);
  seen[x] = true;
  for(auto &nx: rG[x]){
    if(!seen[nx]) dfs(nx, seen, rG, groups);
  }
}

vector<vector<int>> scc(vector<vector<int>> &G, vector<vector<int>> &rG){
  int N = G.size();
  vector<bool> seen(N, false), visited(N, false);
  vector<int> vis;
  for(int i=0;i<N;i++){
    if(!seen[i]) dfs(i, seen, G, vis);
  }
  vector<vector<int>> ret;
  reverse(vis.begin(), vis.end());
  for(auto i: vis){
    if(!visited[i]){
      vector<int> groups;
      rdfs(i, visited, rG, groups);
      ret.push_back(groups);
    }
  }
  return ret;
}

int main(){
  int N, M;
  cin >> N >> M;
  int A, B;
  vector<int> start(N, 1);
  for(int i=0;i<M;i++){
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    start[B]=0;
  }
  for(int i=0;i<N;i++){
    sort(G[i].begin(), G[i].end());
  }

}