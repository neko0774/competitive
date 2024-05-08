#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> C(H, vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> C[i][j];
    }
  }
  vector<int> ans(W, 0);
  for(int x=0;x<W;x++){
    for(int y=0;y<H;y++){
      if(C[y][x]=='#') ans[x] += 1;
    }
  }
  for(int i=0;i<W;i++){
    cout << ans[i] << ' ';
  }
}