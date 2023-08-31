#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15;

int main(){
  ll N;
  cin >> N;
  vector<pair<ll, ll>> ppl;
  ll cnt;
  ll X, Y, Z;
  vector<vector<ll>> dp(N+1, vector<ll>(1e5+1, INF));
  dp[0][0] = 0;
  ll ZZ = 0;
  for(int i=0;i<N;i++){
    cin >> X >> Y >> Z;
    ZZ += Z;
    if(X>(X+Y)/2) cnt=0;
    else cnt = (Y-X)/2+1;
    for(int z=0;z<1e5+1;z++){
      dp[i+1][z] = min(dp[i][z], dp[i][max(z-Z, 0ll)]+cnt);
    }
  }
  ll ans = INF;
  for(int i=ZZ/2+1;i<1e5+1;i++){
    ans = min(ans, dp[N][i]);
  }
  cout << ans << endl;
}