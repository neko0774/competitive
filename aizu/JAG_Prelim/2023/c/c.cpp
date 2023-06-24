#include <bits/stdc++.h>
using namespace std;
bool solve() {
  long long y, c, r;
  cin >> y >> c >> r;
  if( y == 0 ) return false;
  long long ng = 0, ok = 1LL<<50;
  while( ng+1 < ok ) {
    long long M = (ng+ok)/2, m = M;//100: return 1
    for _ in range(y):
      if m<c: return 0
      m = (m-c)*(100+r)//100
    return 1

  while abs(ok-ng)>1:
    m = (ok+ng)//2
    if isok(m): ok = m
    else: ng = m
  print(ok)

  # print(isok(2860))
    for( long long d = 0; d < y; d++ ) {
      if( m < c ) {
        m = -1;
        break;
      }
      m = (m-c)*(100+r)/100;
    }
    if( m >= 0 ) ok = M;
    else ng = M;
  }
  cout << ok << endl;
  return true;
}
int main() {
  while( solve() == true ) {}
}