#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/segtree>


ll ma(ll x, ll y){
  return max(x, y);
}
ll mi(ll x, ll y){
  return min(x, y);
}
ll emax(){
  return 0LL;
}
ll emin(){
  return 1e12;
}

int main(){
  int N;
  cin >> N;
  vector<pair<ll, ll>> P(N);  
  vector<ll> mx(N), mn(N);
  for(int i=0;i<N;i++){
    cin >> P[i].first >> P[i].second;
  }
  sort(P.begin(), P.end());
  for(int i=0;i<N;i++){
    mx[i] = mn[i] = P[i].second;
  }
  atcoder::segtree<ll, ma, emax> seg1(mx);
  atcoder::segtree<ll, mi, emin> seg2(mn);
  ll ng = 1e9 + 5;
  ll ok = 0;
  while(ng - ok > 1LL){
    ll mid = (ok + ng) / 2LL;
    int r = 0;
    bool greater = false;
    for(int l = 0; l < N; l++){
      while(P[r].first - P[l].first < mid && r + 1 < N) r++;
      if((abs(seg1.prod(r, N) - seg2.prod(0, l + 1)) >= mid || abs(seg1.prod(0, l + 1) - seg2.prod(r, N)) >= mid) && P[r].first - P[l].first >= mid){
        greater = true;
      }
    }
    if(greater) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}