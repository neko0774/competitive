#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int shift = 0;
  for(int i=0;i<Q;i++){
    int T, x, y;
    cin >> T >> x >> y;
    x--;
    y--;
    if(T==1){
      swap(A[(N+x-shift)%N], A[(N+y-shift)%N]); 
    }else if(T==2){
      shift++;
      shift%=N;
    }else{
      cout << A[(N+x-shift)%N] << endl;
    }
  }
}