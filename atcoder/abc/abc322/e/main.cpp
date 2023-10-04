#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15;


int main(){
  int N, K, P;
  cin >> N >> K >> P;
  vector<ll> C(N);
  vector<vector<int>> A(N, vector<int>(K));
  for(int i=0;i<N;i++){
    cin >> C[i];
    for(int k=0;k<K;k++){
      cin >> A[i][k];
    }
  }

  vector<vector<ll>> dp(N+1, vector<ll>(4000, INF));
  vector<int> s(K);
  dp[0][0] = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<4000;j++){
      for(int l=0;l<P;l++){
        s[l] = j%P;
        j/=P;
      }
      for(int k=0;k<K;k++){
        s[k] = max(P, A[i][k]+s[k]);
      }
      ll v = 0;
      ll c = 1;
      for(int k=0;k<K;k++){
        v += s[k]*c;
        c *= P;
      }
      dp[i+1][v] = min(dp[i+1][v], dp[i][j]+C[i]);
    }
  }
  ll last = 1;
  for(int i=0;i<K;i++){
    last *= P;
  }
  last -= 1;
  if(dp[N][last]==INF) cout << -1 << endl;
  else cout << dp[N][last] << endl;
}