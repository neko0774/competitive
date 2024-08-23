#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint998244353;
const ll mod = 998244353;


int main(){
  ll N;
  int K;
  cin >> N;
  cin >> K;
  mint rev = mint(N).pow(mod - 2);
  vector<mint> dp(K + 1);
  dp[0] = 1;
  for(ll i = 0;i < K;i++){
    dp[i + 1] = dp[i] * 2 * rev * rev + (1 - dp[i]) * (mint(1) - rev) * rev * 2;
  }
  mint ans;
  ans = dp[K] + (mint(N) * mint(N + 1) / mint(2) - mint(1)) * (mint(1) - dp[K]);
  cout << ans.val() << endl;
}