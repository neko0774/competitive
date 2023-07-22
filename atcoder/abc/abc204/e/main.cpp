#include <bits/stdc++.h>
using namespace std;
const long long INF=1e15;

int main(){
  int N, M;
  vector<vector<tuple<int, int, int>>> G(N);
  vector<int> dist(N, INF);
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    A--;
    B--;
    G[A].push_back(make_tuple(B, C, D));
    G[B].push_back(make_tuple(A, C, D));
  }

  priority_queue<pair<int, long long>> q;
  dist[0] = 0;
  q.push(make_pair(0, 0));
  while(!q.empty()){
    int x = q.top().first;
    long long time = q.top().second;
    q.pop();
    if (dist[x]<time) continue;
    for(auto e:G[x]){
      int nx = get<0>(e);
      int C = get<1>(e);
      int D = get<2>(e);
      
    }
  }
}