#include<bits/stdc++.h>
using namespace std;

void solve(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a>b) swap(a, b);
  if(c>d) swap(c, d);
  if((a<c&&c<b&&b<d&&d<a+12)||(a<c+12&&c+12<b&&b<d&&d<a+12)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return;
}

int main(){
  int T;
  cin >> T;

  while(T--){
    solve();
  }
}