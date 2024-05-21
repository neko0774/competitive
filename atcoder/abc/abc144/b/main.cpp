#include<bits/stdc++.h>
using namespace std;


int main(){
  int N,a,b;
  cin >> N >> a >> b;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int ok = 0, ng = 1e9+1;
  while(ok-ng>1){
    int m = (ok+ng)/2;
    int cnt = 0;
    for(int i=0;i<N;i++){
      if(A[i]<m){
        cnt += (m-A[i]+a-1)/a;
      }else{
        cnt -= (A[i]-m)/b;
      }
    }
    if(cnt<=0){
      ok = m;
    }else{
      ng = m;
    }
  }
  cout << ok << endl;
}