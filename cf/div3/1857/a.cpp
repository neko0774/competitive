#include <bits/stdc++.h>
using namespace std;

void solve(){
  int N;
  cin >> N;
  vector<int> A(N);
  int cnt = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i]%2==1)cnt++;
  }
  if(cnt%2==1) cout << "NO" << endl;
  else cout << "YES" << endl;
}


int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}