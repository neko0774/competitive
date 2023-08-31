#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(vector<ll> &A, ll x){
  ll ret = 0;
  for(auto a: A) ret += abs(a-x);
  return ret;
}

ll sum(vector<ll> &A){
  ll ret = 0;
  for(auto a: A) ret += a;
  return ret;
}

ll median(vector<ll> &A){
  ll N = A.size();
  if(N%2==1) return A[N/2];
  else return (A[N/2]+A[N/2-1])/2;
}

int main(){
  ll N;
  cin >> N;
  vector<ll> X, Y;
  ll ans = 0;
  for(int i=0;i<N;i++){
    int x, y;
    cin >> x >> y;
    X.push_back(x+1e9);
    Y.push_back(y+1e9);
  }

  sort(X.rbegin(), X.rend());
  sort(Y.rbegin(), Y.rend());

  ll XX = 1e18;
  ll YY = 1e18;
  for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){
      XX = min(XX, calc(X, median(X)+i));
      YY = min(YY, calc(Y, median(Y)+i));
    }
  }
  cout << XX+YY << endl;
}