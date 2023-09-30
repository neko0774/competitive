#include <bits/stdc++.h>
using namespace std;



int main(){
  int N, M;
  cin >> N >> M;
  vector<int> size(N);
  for(int i=0;i<M;i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    size[B]++;
  }
  int ans = -1;
  for(int i=0;i<N;i++){
    if(size[i]==0){
      if(ans==-1) ans = i+1;
      else{cout << -1 << endl;return 0;}
    }
  }
  cout << ans << endl;
}