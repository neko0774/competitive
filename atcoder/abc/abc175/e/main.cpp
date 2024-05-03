#include <iostream>
#include <vector>
using namespace std;

int main(){
  int W, H, K;
  cin >> W >> H >> K;
  vector<vector<long long>> items(H+1, vector<long long>(W+1, 0));
  int x,y;
  long long v;
  for(int i=0;i<K;i++){
    cin >> x >> y >> v;
    items[y][x] = v;
  }
  vector<vector<vector<long long>>> dp(H+1, vector<vector<long long>>(W+1, vector<long long>(4, 0)));
  for(int x=1;x<=W;x++){
    for(int y=1;y<=H;y++){
      for(int i=3;i>0;i--){
        dp[y][x][i] = max(dp[y-1][x][i], max(dp[y-1][x][i-1],  dp[y][x-1][3])+items[y][x]);
      }
      dp[y][x][0] = max(dp[y-1][x][0], dp[y][x-1][3]);
    }
  }
  cout << dp[H][W][3] << endl;
}