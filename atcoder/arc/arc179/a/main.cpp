#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<ll> C(N+1, 0);
  if(K<=0){
    sort(A.rbegin(), A.rend());
  }else{
    sort(A.begin(), A.end());
  }


  
  for(int i=0;i<N;i++){
    C[i+1] = C[i]+A[i];
  }
  bool seen = false;
  bool ok = true;
  for(int i=0;i<N+1;i++){
    if(C[i]>=K) seen = true;
    if(seen&&C[i]<K) ok = false;
  }
  if(ok){
    cout << "Yes" << endl;
    for(auto a: A) cout << a << ' ';
  }else{
    cout << "No" << endl;
  }
}