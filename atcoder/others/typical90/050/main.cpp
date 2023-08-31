#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

int main(){
  int N, L;
  cin >> N >> L;
  vector<ll> dp(N+1, 0);
  dp[0] = 1;
  for(int i=1;i<=N;i++){
    if(i-L>=0) dp[i]+=dp[i-L];
    dp[i]+=dp[i-1];
    dp[i]%=MOD;
  }

  cout << dp[N] << '\n';
}