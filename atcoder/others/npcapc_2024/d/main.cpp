#include <bits/stdc++.h>
using namespace std;
#include<atcoder/modint>
using mint = atcoder::modint998244353;

void solve(vector<int> &A, int N, int M){
  int l, r;
  cin >> l >> r;
  l--;
  A[l] = r;
  int size = 1<<M;
  vector<vector<mint>> dp(N+1, vector<mint>(size));
  dp[0][0] = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<size;j++){
      bool is_smaller = false;
      for(int k=0;k<M;k++){
        if(j&(1<<k)){
          //from white box to black box
          dp[i+1][j] += dp[i][j^(1<<k)];
          if(k+1>A[i]){
            is_smaller = true;
            break;
          }
        }else{
          //from black box to white box
          dp[i+1][j] += dp[i][j|(1<<k)];
        }
      }
      if(is_smaller) dp[i+1][j] = 0;
      //cout << j << ' ' << dp[i+1][j].val() << '|';
    }
  }
  mint ans;
  for(int i=0;i<size;i++){
    ans += dp[N][i];
  }
  cout << ans.val() << endl;
}

int main(){
  int N, M, Q;
  cin >> N >> M >> Q;
  assert(Q==1);
  assert(N<=2000);
  assert(M<=15);
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<Q;i++){
    solve(A, N, M);
  }
}