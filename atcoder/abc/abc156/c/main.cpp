#include<bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  int ans = 1e9;
  vector<int> X(N);
  for(int i=0;i<N;i++){
    cin >> X[i];
  }
  for(int xx=0;xx<150;xx++){
    int memo = 0;
    for(auto x: X){
      memo += (x-xx)*(x-xx);
    }
    ans = min(ans, memo);
  }
  cout << ans << endl;
}