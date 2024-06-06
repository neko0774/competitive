#include<bits/stdc++.h>
using namespace std;

int solve(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> fig1, fig2, let1, let2;
  bool seen = false;
  for(auto s: S){
    if('a'<=s&&s<='z'){
      seen = true;
      let2.push_back(s-'a');
      let1.push_back(s-'a');
    }else{
      if(seen){
        cout << "No" << endl;
        return 0;
      }
      fig1.push_back(s-'0');
      fig2.push_back(s-'0');
    }
  }
  sort(fig1.begin(), fig1.end());
  sort(let1.begin(), let1.end());
  if(fig1==fig2&&let1==let2){
    cout << "YES" << endl;
  }else{
    cout <<"NO" << endl;
  }
  return 0;
}

int main(){
  int T;
  cin >> T;
  while(T--){solve();} 
}