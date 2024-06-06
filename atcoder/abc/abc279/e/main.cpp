#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0;i<M;i++){
    cin >> A[i];
    A[i]--;
  }
  vector<int> pos(N), C(N);
  for(int i=0;i<N;i++){
    pos[i] = i;
    C[i] = i;
  }
  vector<int> ans(N);
  for(int i=0;i<M;i++){
    swap(C[A[i]], C[A[i]+1]);
  }
  for(int i=0;i<N;i++){
    ans[C[i]] = i;
  }
  for(int i=0;i<M;i++){
    int x = pos[A[i]], y = pos[A[i]+1];
    if(x==0){
      cout << ans[y]+1 << endl;
    }else if(y==0){
      cout << ans[x]+1 << endl;
    }else{
      cout << ans[0]+1 << endl;
    }
    swap(pos[A[i]], pos[A[i]+1]);
  }
}