#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(ll x, ll y, ll sx, ll sy, ll &W, ll &H, unordered_set<ll> A, vector<vector<bool>> S, ll &ans){
  if(x==sx&&y==sy&&A.size()>=3) ans = max(ans, (ll)A.size());

  for(auto xy: dxy){
    ll nx = x+xy[0];
    ll ny = y+xy[1];
    if(0<=nx&&nx<W&&0<=ny&&ny<H&&A.count(ny*W+nx)==0&&S[ny][nx]){
      A.insert(ny*W+nx);
      dfs(nx ,ny, sx, sy, W, H, A, S, ans);
      A.erase(ny*W+nx);
    }
  }
}

int main(){
  ll H, W;
  cin >> H >> W;
  vector<vector<bool>> C(H, vector<bool>(W, false));
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      char tmp;
      cin >> tmp;
      if(tmp=='.') C[y][x] = true;
    }
  }
  ll ans = 0;
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      if(!C[y][x]) continue;
      unordered_set<ll> a;
      dfs(x, y, x, y, W, H, a, C, ans);
    }
  }
  if(ans==0) cout << -1 << endl;
  else cout << ans << endl;
}