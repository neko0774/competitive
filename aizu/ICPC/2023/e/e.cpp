#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const P MINF = (P){-1, -1};

void chmax(P &x, P y) {
  if( x < y ) x = y;
}

bool solve() {
  P MINF = make_pair(-1, -1);
  int n;
  cin >> n;
  if( n == 0 ) return false;
  vector<P> dp(2*n+1, MINF), ep(2*n+1, MINF);
  dp[0] = make_pair(n-1, n-1);
  for( int i = 0; i < n; i++ ) {
    int x, y;
    cin >> x >> y;
    for( int j = 0; j <= 2*n; j++ ) {
      auto [w, z] = dp[j];
      if( j+0 <= 2*n ) {
        if( make_pair(w, z) >= make_pair(y, x) ) chmax(ep[j], make_pair(y, x));
      }
      if( j+1 <= 2*n ) {
        if( make_pair(w, z) >= make_pair(y, z) ) chmax(ep[j+1], make_pair(y, z));
        if( make_pair(w, z) >= make_pair(w, x) ) chmax(ep[j+1], make_pair(w, x));
      }
      if( j+2 <= 2*n ) {
        if( make_pair(w, z) >= make_pair(w, z) ) chmax(ep[j+2], make_pair(w, z));
      }
    }
    swap(dp, ep);
    fill(ep.begin(), ep.end(), MINF);
  }
  for( int i = 0; i <= 2*n; i++ ) {
    if( dp[i] != MINF ) {
      cout << i << endl;
      break;
    }
  }
  return true;
}

int main() {
  while( solve() ) {}
}