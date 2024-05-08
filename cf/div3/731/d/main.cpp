#include<bits/stdc++.h>
using namespace std;

long long find(long long a, long long &b){
  long long ret = 0;
  for(int i=30;i>=0;i--){
    ret *= 2;
    if(1&a>>i){
      if(!(1&b>>i)){
        ret += 1;
        b |= 1<<i;
      }
    }
  }
  return ret;
}

void solve(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  cout << 0;
  for(int i=1;i<N;i++){
    cout << ' ' << find(A[i-1], A[i]);
  }
  cout << endl;
  return;
}

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    solve();
  }  

  return 0;
}