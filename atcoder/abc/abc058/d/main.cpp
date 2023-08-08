#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;


int main(){
  long long A, B;
  cin >> A >> B;
  vector<long long> X(A), Y(B);
  for(int i=0;i<A;i++){
    cin >> X[i];
  }
  for(int j=0;j<B;j++){
    cin >> Y[j];
  }
  cout << X[A-1]-X[0] << ' ' << Y[B-1]-Y[0] << endl;
  cout << (A-1)%mod*(B-1)%mod*(X[A-1]-X[0])%mod*(Y[B-1]-Y[0])%mod << endl;
}