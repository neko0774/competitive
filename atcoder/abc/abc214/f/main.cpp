#include<bits/stdc++.h>
using namespace std;
#include<atcoder/modint>
using mint = atcoder::modint1000000007;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<mint> dp(N+1);
  vector<vector<int>> nxt(N+2, vector<int>(26, -1));
  for(int i=N-1;i>=0;i--){
    for(int j=0;j<26;j++){
      nxt[i][j] = nxt[i+1][j];
    }
    nxt[i][S[i]-'a'] = i;
  }
  for(int i=0;i<26;i++){
    if(nxt[0][i]!=-1) dp[nxt[0][i]] = 1;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<26;j++){
      if(nxt[i+2][j]!=-1){
        dp[nxt[i+2][j]] += dp[i];
      }
    }
  }
  mint ans;
  for(int i=0;i<N+1;i++){
    //cout << dp[i].val() << ' ';
    ans += dp[i];
  }
  //cout << endl;
  cout << ans.val() << endl;
  return 0;
}