#include <bits/stdc++.h>
using namespace std;
void solve(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int v = A[0];
  int ma = 0;
  int flag = -1;
  for(int i=1;i<N;i++){
    if(A[i]<v)flag = i;
    v = A[i];
  }
  for(int j=0;j<flag+1;j++){
    ma = max(ma, A[j]);
  }
  if(flag==-1) cout << 0 << endl;
  else cout << ma << endl;
}


int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}