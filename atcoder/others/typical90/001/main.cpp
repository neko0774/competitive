#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N, L;
  cin >> N >> L;
  ll K;
  cin >> K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  A.push_back(L);
  ll ok = 0;
  ll bad = 1e17;
  while(abs(ok-bad)>1){
    ll m = (ok+bad)/2;
    ll cnt = -1;
    ll lst = 0;
    for(auto a: A){
      if(a-lst>=m){
        lst = a;
        cnt++;
      }
    }
    if(cnt>=K) ok = m;
    else bad = m;
  }
 cout << ok << endl;
}