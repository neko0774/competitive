#include <bits/stdc++.h>
using namespace std;

bool good(long x, vector<long> &A, long K){
  for(auto &a: A) K -= min(x, a);
  return K>=0;
}


int main(){
  long N, K;
  cin >> N >> K;
  vector<long> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  //went terough n times, and still left smth(=including 0)
  long ok = 0;
  long bad = 1e12+1;
  while(abs(ok-bad)>1){
    long m = (ok+bad)/2;
    if(good(m, A, K)) ok = m;
    else bad = m;
  }
  for(auto &a: A){
    long dec = min(a, ok);
    a -= dec;
    K -= dec;
  }
  for(auto &a: A){
    if (K>0&&a>0){
      a--;
      K--;
    }
  }
  for(auto &a: A) cout << a << ' ';
  cout << endl;
}