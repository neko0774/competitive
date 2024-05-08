#include<bits/stdc++.h>
using namespace std;

string solve(){
  string S;
  cin >> S;
  int l = 0, r = S.length()-1;
  int s = S.length()-1;
  while(r-l>=0){
    //cout << l << ' ' << S[l]-'a' << ' ' << r << ' ' << S[r]-'a' << endl;
    if(S[l]-'a'==s){
      l++;
      s -= 1;
    }else if(S[r]-'a'==s){
      r--;
      s -= 1;
    }else{
      return "No";
    }
  }
  return "Yes";
}

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    cout << solve() << endl;
  }  

  return 0;
}