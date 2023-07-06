#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string S;
  cin >> S;
  if( S == "#" ) return false;
  vector<int> sep;
  sep.push_back(-1);
  for( int i = 0; i < S.size()-1; i++ ) {
    if( S[i] == ')' && S[i+1] == '(' ) sep.push_back(i);
  }
  sep.push_back(S.size()-1);
  int ans = 0;
  for( int i = 0; i < sep.size()-1; i++ ) {
    int L = sep[i]+1, R = sep[i+1], a = 0, b = 0;
    for( int j = L; j <= R; j++ ) {
      if( S[j] == '(' ) a++;
      if( S[j] == ')' ) b++;
    }
    ans += max({0, (b-2*a+1)/2, (a-2*b+1)/2});
  }
  cout << ans << endl;
  return true;
}

int main() {
  while( solve() ) {}
}