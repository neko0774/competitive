#include <bits/stdc++.h>
using namespace std;
bool solve() {
  int H, W;
  cin >> H >> W;
  if( H == 0 ) return false;
  int ans = 0;
  vector<vector<int>> a(H, vector<int>(W));
  for( int i = 0; i < H; i++ ) {
    for( int j = 0; j < W; j++ ) {
      cin >> a[i][j];
    }
  }
  for( int u = 0; u < H; u++ ) {
    for( int l = 0; l < H; l++ ) {
      for( int d = u+3; d <= H; d++ ) {
        for( int r = l+3; r <= W; r++ ) {
          int edge_min = 1<<20, center_max = 0, center_sum = 0;
          for( int i = u; i < d; i++ ) {
            for( int j = l; j < r; j++ ) {
              if( i == u || i == d-1 || j == l || j == r-1 ) {
                edge_min = min(edge_min, a[i][j]);
              }else {
                center_max = max(center_max, a[i][j]);
                center_sum += a[i][j];
              }
            }
          }
          if( edge_min > center_max ) ans = max(ans, (d-u-2)*(r-l-2)*edge_min-center_sum);
        }
      }
    }
  }
  cout << ans << endl;
  return true;
}
int main() {
  while( solve() == true ) {}
}