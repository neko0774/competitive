#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll H, W, x, y;
  cin >> W >> H >> x >> y;
  cout << setprecision(15) << (long double)H*W/2.0 << ' ';
  if(W==x*2&&H==y*2) cout << 1 << endl;
  else cout <<0 << endl;

}