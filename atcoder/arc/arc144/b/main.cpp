#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N,a,b;
  cin >> N >> a >> b;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll ok = 0, ng = 1e9+1;
  while(ng-ok>1){
    ll m = (ok+ng)/2;
    ll cnt = 0;
    for(int i=0;i<N;i++){
      if(A[i]<m){
        cnt -= (m-A[i]+a-1)/a;
      }else{
        cnt += (A[i]-m)/b;
      }
    }
    if(cnt>=0){
      ok = m;
    }else{
      ng = m;
    }
  }
  cout << ok << endl;
}