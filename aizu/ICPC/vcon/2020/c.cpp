#include <bits/stdc++.h>
using namespace std;

// 消し忘れていたらここを消して！
constexpr int K = 3050;
int cost_h[K][K];
int cost_v[K][K];
int dp[K][K];
// ===========================

void chmin(int &x, int y) {
  if( x > y ) x = y;
}

void rotate90(int &x, int &y) {
  swap(x, y);
  x *= -1;
}

bool solve(){
  int n; cin>>n;
  if(n==0)return 0;
  int sx,sy,gx,gy;
  cin>>sx >>sy >>gx >>gy;
  vector<int> x(n),y(n),r(n);
  for(int i=0; i<n; i++)cin >>x[i] >>y[i] >>r[i];

  for( int i = 0; i < K; i++ ) {
    for( int j = 0; j < K; j++ ) {
      cost_h[i][j] = 0;
      cost_v[i][j] = 0;
      dp[i][j] = 1<<20;
    }
  }

  while( sx > gx || sy > gy ) {
    rotate90(sx, sy);
    rotate90(gx, gy);
    for( int i = 0; i < n; i++ ) rotate90(x[i], y[i]);
  }

  int x_min = min(sx, gx), y_min = min(sy, gy);
  for( int i = 0; i < n; i++ ) {
    chmin(x_min, x[i]-r[i]);
    chmin(y_min, y[i]-r[i]);
  }

  sx -= x_min;
  sy -= y_min;
  gx -= x_min;
  gy -= y_min;
  for( int i = 0; i < n; i++ ) {
    x[i] -= x_min;
    y[i] -= y_min;
  }

  for( int i = 0; i < n; i++ ) {
    cost_h[x[i]-r[i]][y[i]-r[i]]++;
    cost_h[x[i]+r[i]+1][y[i]-r[i]]--;
    cost_v[x[i]-r[i]][y[i]-r[i]]++;
    cost_v[x[i]-r[i]][y[i]+r[i]+1]--;
  }
  for( int i = 0; i < K; i++ ) {
    for( int j = 0; j < K-1; j++ ) {
      cost_v[i][j+1] += cost_v[i][j];
    }
  }
  for( int j = 0; j < K; j++ ) {
    for( int i = 0; i < K-1; i++ ) {
      cost_h[i+1][j] += cost_h[i][j];
    }
  }

  dp[sx][sy] = 0;
  for( int i = sx; i <= gx; i++ ) {
    for( int j = sy; j <= gy; j++ ) {
      if( i < gx ) chmin(dp[i+1][j], dp[i][j]+cost_v[i+1][j]);
      if( j < gy ) chmin(dp[i][j+1], dp[i][j]+cost_h[i][j+1]);
    }
  }

  int ans = dp[gx][gy];
  for( int i = 0; i < n; i++ ) {
    if( x[i]-r[i] <= sx && sx <= x[i]+r[i] && y[i]-r[i] <= sy && sy <= y[i]+r[i] ) ans++;
  }

  cout << ans << endl;

  return 1;
}

int main(){
  while(solve()){}
}