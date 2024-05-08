#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int mv = 1e9;
  for(int i=0;i<N;i++){
    cin >> A[i];
    mv = min(mv, A[i]);
  }
  int ans = 1e6;
  int lv = -1;
  for(int i=0;i<N;i++){
    if(lv!=-1&&A[i]==mv){
      ans = min(ans, i-lv);
    }
    if(A[i]==mv)lv=i;
  }
  cout << ans << endl;
}