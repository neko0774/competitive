#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  for(int i=0;i<M;i++){
    cin >> A[i];
  }

  for(int i=0;i<N;i++){
    cout << *lower_bound(A.begin(), A.end(), i+1)-i-1 << endl;
  }
}