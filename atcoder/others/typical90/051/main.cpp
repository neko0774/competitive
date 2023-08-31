#include<bits/stdc++.h>
using namespace std;
#define ll long long

void show(vector<ll> &A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}


void set_ar(vector<vector<ll>> &AA, vector<ll> A){
  for(int i=0;i<A.size();i++){
    for(int j=AA.size()-1;j>=0;j--){
      for(auto aa: AA[j]) AA[j+1].push_back(aa+A[i]);
    }
  }
  for(auto &a: AA) sort(a.begin(), a.end());
}




int main(){
  ll N, K, P;
  cin >> N >> K>> P;
  vector<ll> A(N/2), B(N-N/2);
  for(int i=0;i<N/2;i++){
    cin >> A[i];
  }
  for(int i=0;i<N-N/2;i++){
    cin >> B[i];
  }

  vector<vector<ll>> AA(N/2+1, vector<ll>()), BB(N-N/2+1, vector<ll>());
  AA[0].push_back(0);
  BB[0].push_back(0);
  set_ar(AA, A);
  set_ar(BB, B);
  ll ans = 0;
  //show(A);
  //show(B);
  //for(auto a: BB) show(a);
  for(int i=0;i<AA.size();i++){
    if(0<=K-i&&K-i<BB.size()){
      for(auto a: AA[i]){
        ans += upper_bound(BB[K-i].begin(), BB[K-i].end(), P-a)-BB[K-i].begin(); 
      }
    }
  }
  cout << ans << endl;
}