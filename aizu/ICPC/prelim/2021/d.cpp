#include<bits/stdc++.h>
using namespace std;

bool is_end = false;

template<long long MOD>
struct rolling_hash {
  string s;
  const long long BASE = 9984555LL;
  int len; // s の長さ
  vector<long long> base_pow;
  vector<long long> prefix_hash;
  rolling_hash(string _s) {
    s = _s;
    len = s.size();
    base_pow.resize(len + 1, 1LL);
    prefix_hash.resize(len + 1, 0LL);
    for(int i = 1; i <= len; i++) {
      base_pow[i] = base_pow[i - 1] * BASE % MOD;
    }
    for(int i = 1; i <= len; i++) {
      prefix_hash[i] = (prefix_hash[i - 1] * BASE + s[i - 1]) % MOD; 
    }
  }
  // 0-indexed で index を指定, S[l, r) のハッシュ
  long long hash(int l, int r) {
    return (MOD * MOD + prefix_hash[r] - prefix_hash[l] * base_pow[r - l]) % MOD;
  }
};

void solve() {
  string S;
  cin >> S;
  int N = S.size();
  if(S == "#") {
    is_end = true;
    return;
  }
  if(S.size() == 1) { // コーナーケース
    cout << 0 << endl;
    return;
  }
  rolling_hash<998244353LL> r998(S);
  rolling_hash<1000000007LL> r107(S);
  const long long INF = 1LL << 50;
  vector<long long> dp(N, INF);
  dp[0] = 0;
  for(int i = 0; i < N / 2; i++) {
    if(S[i] == S[N - i - 1]) {
      dp[i + 1] = min(dp[i + 1], dp[i]);
      continue;
    }
    for(int j = i + 1; j <= N / 2; j++) {
      bool same998 = (r998.hash(i, j) == r998.hash(N - j, N - i));
      bool same107 = (r107.hash(i, j) == r107.hash(N - j, N - i));
      if(same998 && same107) {
        dp[j] = min(dp[j], dp[i] + (j - i + 0LL) * (j - i + 0LL));
        break;
      }
    }
  }
  // for(int i = 0; i < N; i++) {
  //   cout << dp[i] << " ";
  // }cout << endl;
  cout << (dp[N / 2] == INF ? -1LL : dp[N / 2]) << endl;
}

int main(){
  while(!is_end) { solve(); }
}