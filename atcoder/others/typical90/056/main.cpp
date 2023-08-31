#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;ll S;
  cin >> N >> S;
  ll A, B;
  vector<pair<ll, ll>> FUKU;
  for(int i=0;i<N;i++){
    cin >> A >> B;
    FUKU.push_back(make_pair(A, B));
  }
  vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
  dp[0][0] = true;
  for(int i=0;i<N;i++){
    for(int j=0;j<S+1;j++){
      if(S+1>j-FUKU[i].first&&j-FUKU[i].first>=0&&dp[i][j-FUKU[i].first]) dp[i+1][j] = dp[i][j-FUKU[i].first];
      if(S+1>j-FUKU[i].second&&j-FUKU[i].second>=0&&dp[i][j-FUKU[i].second]) dp[i+1][j] = dp[i][j-FUKU[i].second];
    }
  }
  vector<char> ans;
  if(!dp[N][S]) cout << "Impossible" << endl;
  else{
    for(int i=N-1;i>=0;i--){
      if(S-FUKU[i].first>=0&&dp[i][S-FUKU[i].first]){
        ans.push_back('A');
        S -= FUKU[i].first;
      }else if(dp[i][S-FUKU[i].second]){
        ans.push_back('B');
        S -= FUKU[i].second;
      }
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans) cout << a;
    cout << endl;
  }
}