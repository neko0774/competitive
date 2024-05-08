#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  cin >> M;
  int l, r;
  for(int i=0;i<M;i++){
    cin >> l >> r;
    l--;
    r--;
    vector<int> cp(r-l+1);
    for(int x=l;x<=r;x++){
      cp[x-l] = A[l];
    }
    for(int x=l;x<=r;x++){
      A[l] = cp[r-x];
    }
  }
  
  
  
}