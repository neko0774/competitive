#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/all>
const ll INF = 1e18;
ll e(){return -INF;}  
ll op(ll a, ll b){return max(a, b);}
ll mapping(ll a, ll b){return (INF == a ? b : a);}
ll composition(ll a, ll b){return (INF == a ? b : a);}
ll id(){return INF;}

int main(){
  ll W, N;
  cin >> W >> N;
  atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id> lseg(vector<ll>(W+1, 0));
  int L, R;
  for(int i=0;i<N;i++){
    cin >> L >> R;L--;
    ll s = lseg.prod(L, R)+1;
    lseg.apply(L, R, s);
    cout << s << endl;
  }
}