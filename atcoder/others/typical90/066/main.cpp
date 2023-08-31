#include<bits/stdc++.h>
using namespace std;
#define ll long long

long double cnt(pair<ll, ll> f, pair<ll, ll> s){
  long double c=0.0;
  ll cc = 0;
  for(ll l=f.first;l<=f.second;l++){
    for(ll r=s.first;r<=s.second;r++){
      if(l>r)c++;
      cc++;
    }
  }
  return c/(long double)cc;
}

int main(){
  ll N;
  cin >> N;
  ll L, R;
  vector<pair<ll, ll>> ary;
  for(int i=0;i<N;i++){
    cin >> L >> R;
    ary.push_back(make_pair(L, R));
  }
  long double ans = 0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      ans += cnt(ary[i], ary[j]);
    }
  }
  cout << setprecision(15) << ans << endl;
}