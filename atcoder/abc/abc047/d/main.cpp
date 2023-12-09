#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e9;

int main(){
  ll N, T;
  cin >> N >> T;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll mi = INF;
  vector<ll> dif = {-1};
  for(auto a: A){
    if(a-mi>=dif.back()){
      dif.push_back(a-mi);
    }
    if(mi>a){
      mi = a;
    }
  }
  ll ans = 0;
  for(auto v:dif){
    if(v==dif.back())ans++;
  }
  cout << ans << endl;

}