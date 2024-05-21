#include<bits/stdc++.h>
using namespace std;


void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  if((a+b+c)%2==1){
    cout << -1 << endl;
    return;
  }
  int ans = a;
  while(a){
    if(b>c)b--;
    else c--;
    a--;
  }
  ans += min(b, c);
  cout << ans << endl;
  return;
}

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    solve();
  }
}