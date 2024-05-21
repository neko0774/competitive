#include<bits/stdc++.h>
using namespace std;


void solve(){
  string S;
  cin >> S;
  char l='a';
  int cnt = 0;
  int flag = 0;
  for(auto s: S){
    if(s!=l) cnt++;
    if(l=='0'&&s=='1') flag = 1;
    l = s;
  }
  cout << cnt-flag << endl;
  return;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}