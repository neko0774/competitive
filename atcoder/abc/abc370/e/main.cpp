#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint998244353;

int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  unordered_map<ll, mint> dp;
  dp[0] = 1;
  mint total = 1;
  ll value = 0;
  for(int i = 0;i < N;i++){
    value += A[i];
    mint nxt = total - dp[value - K];
    dp[value] += nxt;
    total += nxt;
    if(i == N - 1)cout << nxt.val() << endl;
  }
}