#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint1000000007;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<vector<mint>> dp(N, vector<mint>(2));
  dp[0][S[0]-'A']++;
  for(int i=1;i<N;i++){
    if(i+1<N&&S[i]=='B'&&S[i+1]=='A') dp[i+1][0] += dp[i-1][0]*2;
    else if(i+1<N&&S[i]=='A'&&S[i+1]=='B') dp[i+1][1] += dp[i-1][1]*2;
    else{
      dp[i]+1
    }
  }
  for(int i=0;i<N;i++){
    cout << dp[i][0].val() << ' ' << dp[i][1].val() << endl;
  }
  mint ans = dp[N-1][0] + dp[N-1][1];
  cout << ans.val() << endl;
}