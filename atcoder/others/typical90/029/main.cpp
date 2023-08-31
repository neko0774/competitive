#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/all>
const ll INF = 1e18;
ll e(){return -INF;}
ll op(ll a, ll b){return max(a, b);}
ll mapping(ll a, ll b){return max(a, b);}
ll composition(ll a, ll b){return max(a, b);}
ll id(){return 0;}

int main(){
  ll W, N;
  cin >> W >> N;
  atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(W+1);
}