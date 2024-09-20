#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll g(ll x) {
  if(x % 2 == 0) return x / 2;
  return g((x - 1) / 2);
}

void solve() {
  ll N, M;
  cin >> N >> M;
  ll g_all = g(N) ^ g(M);
  cout << (g_all == 0 ? "Second" : "First") << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T--) solve();
}