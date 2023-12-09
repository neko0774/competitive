#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  string S;
  cin >> S;
  int N = S.size()-1;
  ll ans = 0;
  for(int i=0;i<(1<<N);i++){
    ll memo = S[0]-'0';
    for(int j=0;j<N;j++){
      if(1<<j&i){
        ans += memo;
        memo = 0;
      }
      memo = memo*10+(S[j+1]-'0');
    }
    ans += memo;
  }
  cout << ans << endl;
}