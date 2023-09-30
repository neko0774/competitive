#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<ll> dp(7, 0);
  for(auto s: S){
    if(s=='a') dp[0]++;
    else if(s=='t') dp[1] += dp[0];
    else if(s=='c') dp[2] += dp[1];
    else if(s=='o') dp[3] += dp[2];
    else if(s=='d') dp[4] += dp[3];
    else if(s=='e') dp[5] += dp[4];
    else if(s=='r') dp[6] += dp[5];
    for(auto &a: dp) a%=mod;
  }
  cout << dp[6] << endl;
}