#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
  int N;
  ll A, B;
  cin >> N >> A >> B;
  vector<ll> ary(2*N);
  for(int i=0;i<2*N;i++){
    cin >> ary[i];
  }
  sort(ary.begin(), ary.end());
  vector<ll> dp = {0, 0};
  vector<ll> rem = {-1, -1};
  for(int i=0;i<N;i++){
    vector<ll> ndp = {0, 0};
    vector<ll> nrem = {-1, -1};
    //rem does not exist
    ll v1 = ary[2*i];
    ll v2 = ary[2*i+1];
    if(v2-v1>A){
      cout << -1 << endl;
      return;
    }
    //no rem = 0
    ndp[0] = dp[0] + (v2-v1<=B);
    if(rem[0]!=-1){
      if(v1-rem[0]<=B&&v2-rem[1]<=B) ndp[0] = dp[1] + 2;
      else if(v1-rem[1]<=B&&v2-rem[0]<=A) ndp[0] = dp[1] + 1;
    }

    //rem exist
    if(rem[0]!=-1){
      if(rem[1]-rem[0]<=B){
        ndp[1] = dp[1]+1;
        nrem = {v1, v2};
      }else if(v1-rem[0]<=B&&v2-rem[1]<=A){
        //rem = a2, v2
        ndp[1] = dp[1] + 1;
        nrem = {rem[1], v2};
      }else if(v1-rem[1]<=B&&v2-rem[0]<=A){
        //rem = a1, v1
        ndp[1] = dp[1] + 1;
        nrem = {rem[0], v2};
      }else if(v2-v1<=B){
        ndp[1] = dp[1] + 1;
        nrem = rem;
      }else{
        ndp[1] = max(dp[1] + (rem[1]-rem[0]<=B), dp[0]);
        nrem = {v1, v2};
      }
    }else{
      ndp[1] = dp[0];
      nrem  = {v1, v2};
    }

    //rem = (v1, v2)
    //cout << dp[0] << ' ' << dp[1] << '|';
    //cout << rem[0] << ' ' << rem[1] << endl;
    swap(dp, ndp);
    swap(rem, nrem);
  }
  //cout << dp[0] << ' ' << dp[1] << '|';
  //cout << rem[0] << ' ' << rem[1] << endl;
  int ans = max(dp[0], dp[1]+(rem[1]-rem[0]<=B));
  cout << ans << endl;
}

int main(){
  int T;
  cin >> T;
  while(T--)solve();
}