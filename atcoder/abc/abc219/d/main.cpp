#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 500;

int main(){
  int N;
  cin >> N;
  int X, Y;
  cin >> X >> Y;
  vector<vector<int>> dp(301, vector<int>(301, INF));
  int A, B;
  dp[0][0] = 0;
  for(int i=0;i<N;i++){
    cin >> A >> B;
    for(int x=300;x>=0;x--){
      for(int y=300;y>=0;y--){
        int ny = min(y+B, 300);
        int nx = min(x+A, 300);
        dp[ny][nx] = min(dp[ny][nx], dp[y][x]+1);
      }
    }
  }
  int ans = 500;
  for(int x=X;x<301;x++){
    for(int y=Y;y<301;y++){
      ans = min(ans, dp[y][x]);
      //if(dp[N][y][x]!=INF)cout << x << ' ' << y << ' ' << dp[N][y][x] << endl;
    }
  }
  cout << (ans==500?-1:ans) << endl;
}
