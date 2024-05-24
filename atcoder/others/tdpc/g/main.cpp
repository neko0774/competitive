#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

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
        if(memo>=INF) dp[i][c] = INF;
        else dp[i][c] = memo + 1;
      }else{
        dp[i][c] = dp[i+1][c];
      }
      if(keep>=INF) continue;
      else keep += dp[i][c];
    }
    memo = keep;
  }
  string ans = "";
  if(memo<K){
    cout << "Eel" << endl;
    return 0;
  }
  for(int i=0;i<N;++i){
    char s;
    int j;
    for(j=0;j<26;j++){
      if(dp[i][j]>=K){
        break;
      }
      K -= dp[i][j];
    }
    s = 'a'+ (char)j;
    ans += s;
    K--;
    if(K<=0) break;
    while(S[i]!=s)i++;
  }
  cout << ans << endl;
}