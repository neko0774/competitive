#include<bits/stdc++.h>
using namespace std;

void solve(){
  int N, M, K;
  cin >> K >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<M;i++){
    cin >> B[i];
  }

  int a = 0, b = 0;
  vector<int> ans(N+M);
  for(int i=0;i<N+M;i++){
    if(a<N&&A[a]<=K){
      if(A[a]==0)K++;
      ans[i] = A[a];
      a++;
    }else if(b<M&&B[b]<=K){
      if(B[b]==0)K++;
      ans[i] = B[b];
      b++;
    }else{
      cout << -1 << endl;
      return;
    }
  }
  for(auto a:ans){
    cout << a << ' ';
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