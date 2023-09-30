#include<bits/stdc++.h>
using namespace std;
#define ll long long


void show(vector<ll> A){
  for(auto a: A) cout <<a << ' ';
  cout << endl;
}

int main(){
  ll N, Q;
  cin >> N >> Q;
  vector<pair<ll, ll>> P;
  vector<ll> X, Y;
  ll x,y;
  for(int i=0;i<N;i++){
    cin >> x >> y;
    P.push_back(make_pair(x, y));
    X.push_back(x+y);
    Y.push_back(x-y);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int q; 
  for(int i=0;i<Q;i++){
    cin >> q;
    q--;
    ll x = P[q].first, y = P[q].second;
    ll xx = x+y, yy = x-y;
    //cout << xx << ' ' << yy << endl;
    cout << max(max(abs(X[0]-xx), abs(X[N-1]-xx)), max(abs(Y[0]-yy), abs(Y[N-1]-yy))) << endl;
  }
}