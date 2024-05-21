#include<bits/stdc++.h>
using namespace std;

void solve(){
  string S;
  cin >> S;
  vector<int> count(27);
  for(auto s: S){
    count[s-'a']++;
  }
  string ans1="";
  string ans2="";
  int i = 0;
  for(auto a: count){
    ans1 += (i+'a')*a;
    ans2 = (i+'a')*a + ans2;
    if(a==S.length()){
      cout << "No" << endl;
      return;
    }
  } 
  if(ans1==S){
    cout << ans2 << endl;
  }else{
    cout << ans1 << endl;
  }
  return;
}


int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    solve();
  }
}