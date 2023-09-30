#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int main(){
  ll K;
  cin >> K;
  vector<ll> dp(K+1, 0);
  if(K%9!=0){
    cout << 0 << endl;
    return 0;
  } 
  dp[0] = 1;
  ll cnt = 1;
  for(int i=0;i<K;i++){
    dp[i+1] = cnt;
    cnt += dp[i+1];
    if(i-8>=0)cnt-=dp[i-8];
    cnt = (cnt+mod)%mod;
  }
  cout << dp[K] << endl;
}