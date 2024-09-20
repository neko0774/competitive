#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  ll H;
  cin >> N >> M >> H;
  vector<ll> dmg(M + 1);
  for(int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    dmg[l]++, dmg[r + 1]--;
  }

  for(int i = 0; i < M; i++) {
    dmg[i + 1] += dmg[i];
  }

  for(int i = M - 1; i >= 0; i--) {
    // cout << H << endl;
    if(i == 0) {
      cout << -1 << endl;
      break;
    }
    else {
      H -= dmg[i];
      if(H <= 0) {
        cout << i << endl;
        break;
      }
    }
  }
}