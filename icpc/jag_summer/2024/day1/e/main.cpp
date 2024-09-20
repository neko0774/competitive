#include<bits/stdc++.h>
using namespace std;

using ld = long double;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int B, N;
  cin >> B >> N;
  vector<ld> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector co(N + 1, vector<ld>(N + 1));
  for(int l = 0; l <= N; l++) {
    ld sq = 0;
    ld sm = 0;
    for(int r = l + 1; r <= N; r++) {
      sm += A[r - 1];
      sq += A[r - 1] * A[r - 1];
      const ld avg = sm / (ld)(r - l);
      co[l][r] = sq + (ld)(r - l) * avg * avg - 2 * avg * sm;
    }
  }

  // for(int i = 0; i < N; i++) {
  //   for(int j = i + 1; j <= N; j++) {
  //     cout << co[i][j] << " ";
  //   } cout << "\n";
  // }

  vector dp(N + 1, vector<ld>(B + 1, INFINITY));
  dp[0][0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      for(int k = 0; k < B; k++) {
        dp[j][k + 1] = min(dp[j][k + 1], dp[i][k] + co[i][j]);
      }
    }
  }

  ld ans = INFINITY;
  for(int i = 0; i <= B; i++) {
    ans = min(ans, dp[N][i]);
  }
  cout << fixed << setprecision(10) << ans << endl;
}