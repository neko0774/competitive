#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint998244353;
const ll INF = 1e18;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  map<tuple<ll, ll, ll>, mint> dp;
  for(int i=0;i<N;i++){
    map<tuple<ll, ll, ll>, mint> ndp = dp;
    ndp[{-INF, A[i], 1}]++;
    for(auto [P, k]: dp){
      if(get<0>(P) == -INF){
        ndp[make_tuple(A[i] - get<1>(P), get<1>(P), get<2>(P) + 1)] += k;
      }else if(get<1>(P) + get<0>(P) * get<2>(P) == A[i]){
        ndp[make_tuple(get<0>(P), get<1>(P), get<2>(P) + 1)] += k;
      }
    }
    //cout << i << endl;
    //for(auto [P, k]: dp) cout << get<0>(P) << ' ' << get<1>(P) << ' ' << get<2>(P) << ' ' << k << endl;
    //cout  << endl;
    swap(dp, ndp);
  } 
  vector<mint> ans(N);
  for(auto [P, k]: dp) ans[get<2>(P) - 1]+=k;
  for(int i=0;i<N;i++){
    cout << ans[i].val() << ' ';
  }
}