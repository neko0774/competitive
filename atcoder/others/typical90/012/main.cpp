#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/dsu>


int main(){
  ll H, W;
  cin >> H >> W;
  int Q;
  cin >> Q;
  ll N = H*W+1e3;
  atcoder::dsu uf(N);
  vector<bool> is_red(N, false);
  vector<vector<int>> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for(int i=0;i<Q;i++){
    int q;
    cin >> q;
    if(q==1){
      ll y, x;
      cin >> y >> x;
      x--;
      y--;
      is_red[y*W+x] = true;
      for(auto p: dxy){
        ll nx = x+p[0];
        ll ny = y+p[1];
        ll nn = ny*W+nx;
        if(0<=nx&&nx<W&&0<=ny&&ny<H&&is_red[nn]) uf.merge(nn, y*W+x);
      }
    }else{
      ll sx, sy, gx, gy;
      cin >> sy >> sx >> gy >> gx;
      sx--;
      sy--;
      gx--;
      gy--;
      if(uf.same(sy*W+sx, gy*W+gx)&&is_red[sy*W+sx]&&is_red[gy*W+gx]){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}