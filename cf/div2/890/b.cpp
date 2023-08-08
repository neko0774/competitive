#include <bits/stdc++.h>
using namespace std;

void solve(){
  long long N;
  cin >> N;
  vector<long long> A(N);
  long long v = 0;
  long long cnt=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    v += A[i];
    if(A[i]==(long long)1)cnt++;
  }
  if(N==1){
    cout << "NO" << endl;
    return;
  }else if(cnt>v-N){
    cout << "NO" << endl;
    return;
  }else{
    cout << "YES" << endl;
    return;
  }
}


int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}