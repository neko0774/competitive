#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  string S;
  cin >> S;
  ll K;
  cin >> K;
  int N = S.size();
  vector<vector<ll>> dp(N+1, vector<ll>(26,0));
  ll memo = 0;
  for(int i=N-1;i>=0;i--){
    ll keep = 0;
    for(int c=0;c<26;c++){
      if(S[i]-'a'==c){
        dp[i][c] = memo + 1;
      }else{
        dp[i][c] = dp[i+1][c];
      }
      keep += dp[i][c];
    }
    memo = keep;
  }
  string ans = "";
  
  
  for(int i=0;i<N;i++){
    char s = 'a';
    ll cnt = dp[i][0];
    for(int j=1;j<26;j++){
      if(cnt>dp[i][1]){
        s = (char)('a'+j);
        cnt = dp[i][1];
      }
    ans += s;
    }
  }
  cout << ans << endl;
}