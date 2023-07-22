#include <bits/stdc++.h>
using namespace std;
const int INF=1000000000;

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
  priority_queue<pair<int, int>> q;
  while(!q.empty()){
    for(int i=0;i<N;i++){
      
      
    }
  }
}