#include <bits/stdc++.h>
using namespace std;
#define ll long long


void show(vector<int> p){
  for(auto pp:p )cout << pp << ' ';
  cout << endl;
}


int main(){
  int N; cin >> N;
  ll X, C;
  map<int, vector<int>> place;
  for(int i=0;i<N;i++){
    cin >> X >> C;
    place[C].push_back(X);
  }
  pair<ll, ll> ans;
  pair<ll, ll> nans;
  ll l=0, r=0;
  for(auto x: place){
    vector<int> p = x.second;
    sort(p.begin(), p.end());
    //cout << *(--p.end()) << ' ' << *p.begin() << endl;
    ll rr = *(--p.end());
    ll dif = abs(rr-*p.begin());
    nans.first = min(abs(l-rr)+ans.first, abs(r-rr)+ans.second)+dif;
    nans.second = min(abs(l-*p.begin())+ans.first, abs(r-*p.begin())+ans.second)+dif;
    l = *p.begin(), r = rr;
    ans = nans;
  }
  cout << min(ans.first+abs(l), ans.second+abs(r)) << endl;
}