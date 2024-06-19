#include <bits/stdc++.h>
using namespace std;

using area = array<int, 4>;

vector<vector<area>> dfs(int l, int r, int u, int d, int rem, bool ho, bool ve) {
  vector<vector<area>> ret;
  if(rem == 0) {
    area A = area{l, r, u, d};
    vector<area> V = {A};
    ret.push_back(V);
    return ret;
  }
  if(ho && l < r) {
    for(int m = l; m <= r - 1; m++) {
      for(int rem2 = 0; rem2 <= rem; rem2++) {
        vector<vector<area>> X = dfs(l, m, u, d, rem2, false, true);
        vector<vector<area>> Y = dfs(m + 1, r, u, d, rem - rem2, false, true);
        for(const auto &xv : X) for(const auto &yv : Y) {
          vector<area> zv;
          zv.insert(zv.end(), xv.begin(), xv.end());
          zv.insert(zv.end(), yv.begin(), yv.end());
          ret.push_back(zv);
        }
      }
    }
  }
  if(ve && u < d) {
    for(int m = u; m <= d - 1; m++) {
      for(int rem2 = 0; rem2 <= rem; rem2++) {
        vector<vector<area>> X = dfs(l, r, u, m, rem2, true, false);
        vector<vector<area>> Y = dfs(l, r, m + 1, d, rem - rem2, true, false);
        for(const auto &xv : X) for(const auto &yv : Y) {
          vector<area> zv;
          zv.insert(zv.end(), xv.begin(), xv.end());
          zv.insert(zv.end(), yv.begin(), yv.end());
          ret.push_back(zv);
        }
      }
    }
  }
  return ret;
}

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<vector<area>> div = dfs(0, H - 1, 0, W - 1, N - 1, true, true);
  vector<vector<long long>> a(H + 1, vector<long long>(W + 1));
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      cin >> a[i][j];
    }
  }
  for(int i = 0; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  for(int j = 0; j <= W; j++) {
    for(int i = 1; i <= H; i++) {
      a[i][j] += a[i - 1][j];
    }
  }
  auto f = [&](int u, int d, int l, int r) -> long long {
    return a[d + 1][r + 1] + a[u][l] - a[d + 1][l] - a[u][r + 1];
  };
  long long ans = 0;
  for(const auto &v : div) {
    assert(v.size() == N);
    long long cur = 1LL << 60;
    for(const auto &[u, d, l, r] : v) {
      cur = min(cur, f(u, d, l, r));
    }
    for(const auto &[u, d, l, r] : v) {
      cout << u << " " << d << " " << l << " " << r << endl;
    }cout << endl;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}