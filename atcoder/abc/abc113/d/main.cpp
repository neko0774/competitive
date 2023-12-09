#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007 ;



int main(){
  int H, W, K;
  cin >> H >> W >> K;
  if(W==1){
    cout << 1 << endl;
    return 0;
  }
  vector<vector<ll>> dp(H+1, vector<ll>(W, 0));
  dp[0][0] = 1;
  for(int i=0;i<H;i++){
    for(int j=0;j<1<<(W-1);j++){
      bool ok = true;
      for(int k=1;k<W-1;k++){
        if((j & 1<<k) && (j & (1<<(k-1)) )){
          ok = false;
          break;
        }
      }
      if(ok){
        vector<int> is_swap(W);
        for(int k=0;k<W;k++){
          is_swap[k] = k;
        }
        for(int k=0;k<W-1;k++){
          if(j&(1<<k))swap(is_swap[k], is_swap[k+1]);
        }
        for(int k=0;k<W;k++){
            dp[i+1][is_swap[k]] += dp[i][k];
            dp[i+1][is_swap[k]] %= mod;
          }
        }
      }
    }
  cout << dp[H][K-1] << endl;
}