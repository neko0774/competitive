#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9+7;

ll sum(vector<ll> A, ll N){
  ll ret = 0;
  for(int i=0;i<N;i++){
    ret += (i*A[i])-(N-i-1)*A[i];
    ret %= mod;
  }
  return ret;
}

int main(){
  ll N, M;
  cin >> N >> M;
  vector<long long> X(N), Y(M);
  for(int i=0;i<N;i++){
    cin >> X[i];
  }
  for(int j=0;j<M;j++){
    cin >> Y[j];
  }
  cout << sum(X, N)*sum(Y, M)%mod<<endl;
}