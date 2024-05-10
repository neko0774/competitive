#include<bits/stdc++.h>
using namespace std;

bool is_end = false;
using ll = long long;

void solve() {
  int K;
  cin >> K;
  if(K == 0) {
    is_end = true;
    return;
  }
  string S;
  cin >> S;
  int N = S.size();
  vector<ll> pw(K, 1);
  for(int i = 1; i < K; i++) {
    pw[i] = pw[i - 1] * 10;
  }
  const ll INF = 1LL << 58;
  vector<ll> dp(K, -INF), ep(K, -INF);
  dp[K - 1] = 0;
  for(const char &c : S) {
    ll d = c - '0';
    for(int i = 0; i < K; i++) {
      ep[i] = max(ep[i], dp[i]);
      ep[(i + 1) % K] = max(ep[(i + 1) % K], dp[i] + pw[K - (i + 1) % K - 1] * d);
    }
    // for(int i = 0; i < K; i++) {
    //   cout << ep[i] << " ";
    // }cout << endl;
    swap(dp, ep);
    fill(ep.begin(), ep.end(), -INF);
  }
  cout << dp[K - 1] << endl;
}

int main() {
  while(!is_end) { solve(); }
}