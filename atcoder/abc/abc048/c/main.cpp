#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N, X;
  cin >> N >> X;
  vector<ll> BOX(N);
  for(int i=0;i<N;i++){
    cin >> BOX[i];
  }
  ll ans = 0;
  if(BOX[0]>X){
    ans += BOX[0]-X;
    BOX[0] = X;
  }
  for(int i=0;i<N-1;i++){
    if(BOX[i]+BOX[i+1]>X){
      ans += BOX[i]+BOX[i+1]-X;
      BOX[i+1] = max(X-BOX[i], 0ll);
    }
  } 
  cout << ans << endl;


}