#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void show(vector<int> A){
  for(auto x: A) cout << x << ' ';
  cout << '\n';
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> dist(N+1, 0);
  vector<int> C(M+1, 0);
  vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
  for(int i=1;i<N+1;i++){
    cin >> dist[i];
  }
  for(int i=1;i<M+1;i++){
    cin >> C[i];
  }

  dp[0][0] = 0;
  for(int i=1;i<N+1;i++){
    int tmp = INF;
    for(int j=1;j<M+1;j++){
      tmp = min(dp[i-1][j-1], tmp);
      dp[i][j] = min(tmp+C[j]*dist[i], dp[i][j-1]);
    }
  }
  cout << dp[N][M] << endl;
}