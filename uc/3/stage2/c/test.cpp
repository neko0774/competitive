#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e9;
void solve(){
  ll N;
  cin >> N;
  vector<vector<ll>> grid(N, vector<ll>(N));
  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      cin >> grid[i][j];
    }
  }

  ll m = N/2;
  ll cent = grid[m][m];
  vector<ll> mid(4, inf);
  vector<ll> corn(4, inf);
  for(ll k=0;k<4;k++){
    for(ll i=0;i<m;i++){
      if(k==0) mid[k] = min(mid[k], grid[m][i]);
      else if(k==1) mid[k] = min(mid[k], grid[m][i+m+1]);
      else if(k==2) mid[k] = min(mid[k], grid[i][m]);
      else mid[k] = min(mid[k], grid[i+m+1][m]);
    }
  }
  for(ll k=0;k<4;k++){
    for(ll i=0;i<m;i++){
      for(ll j=0;j<m;j++){
        if(k==0) corn[k] = min(corn[k], grid[i][j]);
        else if(k==1) corn[k] = min(corn[k], grid[i][j+m+1]);
        else if(k==2) corn[k] = min(corn[k], grid[i+m+1][j]);
        else corn[k] = min(corn[k], grid[i+m+1][j+m+1]);
      }
    }
  }
  //1
  ll ans = cent;
  //2 tu
  ll mv = min(mid[0]+mid[1], mid[2]+mid[3]);
  ans = min(mv, ans);
  //3
  vector<ll> ma = {mid[0]+corn[1]+corn[3], mid[1]+corn[0]+corn[2], mid[2]+corn[2]+corn[3], mid[3]+corn[0]+corn[1]};
  for(auto v: ma) ans = min(ans, v);
  //4
  ans = min(ans, corn[0]+corn[1]+corn[2]+corn[3]);
  cout << ans << endl;
}

int main(){
  ll T;
  cin >> T;
  while(T--) solve();
}