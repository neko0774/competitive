#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> count(vector<vector<int>> &G, int s){
  vector<int> dist(G.size(),0);
  queue<int> q;
  q.push(s);
  dist[s] = 1;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(auto nx: G[x]){
      if(dist[nx]==0){
        dist[nx] = dist[x]+1;
        q.push(nx);
      }
    }
  }
  return dist;
}



int main(){
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  for(int i=0;i<N-1;i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> d1 = count(G, 0);
  vector<int> d2 = count(G, N-1);
  int cnt = 0;
  for(int i=0;i<N;i++){
    if(d1[i]<=d2[i])cnt++;
    else cnt--;
  }
  if(cnt>0)cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
}