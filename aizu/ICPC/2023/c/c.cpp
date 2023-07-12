#include <bits/stdc++.h>
using namespace std;

bool judge(vector<vector<int>> a, vector<vector<int>> b) {
  int n = a.size();
  vector<int> x(n*n), y(n*n);
  vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      int z = b[i][j]-1;
      x[z] = i, y[z] = j;
    }
  }
  auto ok = [&](int r, int c) -> bool {
    return 0 <= r && r < n && 0 <= c && c < n;
  };
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      for( auto [xx, yy] : v ) {
        if( ok(i+xx, j+yy) ) {
          int z = a[i+xx][j+yy]-1, w = a[i][j]-1;
          if( abs(x[z]-x[w])+abs(y[z]-y[w]) < n/2 ) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

bool solve() {
  int n;
  cin >> n;
  if( n == 0 ) return false;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> a_copy(n, vector<int>(n));
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      cin >> a[i][j];
      a_copy[i][j] = a[i][j];
      // a[i][j] = a_copy[i][j] = i*n+j+1;
    }
  }
  for( int i = 0; i < n; i++ ) {
    int k = i*(n/2);
    rotate(a[i].begin(), a[i].begin()+k%n, a[i].end());
  }
  for( int i = 0; i < n; i++ ) {
    for( int j = i; j < n; j++ ) {
      swap(a[i][j], a[j][i]);
    }
  }
  for( int i = 0; i < n; i++ ) {
    int k = i*(n/2);
    rotate(a[i].begin(), a[i].begin()+k%n, a[i].end());
  }
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      cout << a[i][j] << " \n"[j==n-1];
    }
  }
  // cout << judge(a_copy, a) << endl;
  return true;
}

int main(){
  while( solve() ) {}
}