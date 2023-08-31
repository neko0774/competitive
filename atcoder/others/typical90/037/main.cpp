#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
#include<atcoder/segtree>


ll op(ll a, ll b){return max(a, b);}
ll e(){return -INF;}

int main(){
  ll W, N;
  cin >> W >> N;
  ll L, R, V;
  atcoder::segtree<ll, op, e> dp(W+1);
  dp.set(0, 0);
  for(int i=0;i<N;i++){
    cin >> L >> R >> V;
    for(int j=W;j>=L;j--){
      ll r = max(0ll, j-L)+1, l = max(0ll, j-R);
      if(dp.prod(l, r)+V>dp.get(j)) dp.set(j, dp.prod(l, r)+V);
    }
  }
  cout << max(-1ll, dp.get(W)) << endl;
}