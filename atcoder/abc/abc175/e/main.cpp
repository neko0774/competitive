#include <iostream>
#include <vector>
using namespace std;

int main(){
  int W, H, K;
  cin >> H >> W >> K;
  vector<vector<long>> item(H+1, vector<long>(W+1, 0));
  vector<vector<vector<long>>> dp(H+1, vector<vector<long>>(W+1, vector<long>(4, 0)));
  for(int i=0;i<K;i++){
    int w, h; long v;
    cin >> h >> w >> v;
    item[h][w] = v;
  }

  for(int y=1;y<H+1;y++){
    for(int x=1;x<W+1;x++){
      for(int i=0;i<4;i++){
        dp[y][x][i] = max(dp[y][x-1][i], dp[y-1][x][3]);
        if(i!=0) dp[y][x][i] = max(dp[y][x][i], max(dp[y][x-1][i-1], dp[y-1][x][3])+item[y][x]);
      }
    }
  }
  cout << dp[H][W][3] << endl;
}