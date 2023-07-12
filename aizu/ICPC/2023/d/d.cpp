#include <bits/stdc++.h>
using namespace std;

vector<int> extract(vector<int> g, vector<bool> in) {
  vector<int> ret;
  for( int i = 0; i < g.size(); i++ ) {
    if( !in[i] ) ret.push_back(g[i]);
  }
  return ret;
}

bool solve() {
  int n;
  cin >> n;
  if( n == 0 ) return false;
  string s;
  cin >> s;
  vector<int> c;
  for( int i = 1; i <= n; i++ ) {
    if( s[i] == 'o' ) {
      c.push_back(i);
    }
  }
  int m = c.size();
  vector<int> g;
  for( int S = 1; S <= n; S++ ) {
    bool flag = true, all_zero = true;
    for( int i = 0; i < m; i++ ) {
      if( (c[i]&S) != 0 ) all_zero = false;
      if( (c[i]&S) != 0 && (c[i]&S) != S ) flag = false;
    }
    if( flag && !all_zero ) {
      g.push_back(S);
    }
  }
  // for( int _g : g ) cout << _g << " ";
  // cout << endl;
  int k = g.size();
  vector<bool> in(k, false);
  for( int i = 0; i < k; i++ ) {
    for( int j = 0; j < k; j++ ) {
      if( i != j && (g[i]&g[j]) == g[j] ) in[j] = true;
    }
  }
  // for( int i = 0; i < k; i++ ) {
  //   if( !in[i] ) cout << g[i] << " ";
  // }cout << endl;
  g = extract(g, in);
  cout << g.size() << endl;
  return true;
}

int main() {
  while( solve() ) {}
}