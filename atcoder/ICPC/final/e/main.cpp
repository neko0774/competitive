#include<bits/stdc++.h>
using namespace std;

bool solve() {
  int n;
  cin >> n;
  if(n == 0) {
    return false;
  }
  vector<int> C(n);
  for(int i = 0; i < n; i++) {
    cin >> C[i];
  }
  vector ans(n, vector<int>(n));
  vector pos(n, vector<pair<int, int>>(n));
  vector used(n, vector<bool>(n));
  vector<bool> used_c(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      pos[i][j] = make_pair(i, j);
    }
  }
  auto color = [&](int i, int j, int co) -> void {
    auto [r, c] = pos[i][j];
    ans[r][c] = co;
    used[i][j] = true;
  };
  auto get = [&](int i, int j) -> int {
    auto [r, c] = pos[i][j];
    return ans[r][c];
  };
  auto rebuild = [&]() -> void {
    const int m = C.size();
    vector<vector<pair<int, int>>> pos_new;
    vector<vector<bool>> used_new;
    vector<bool> used_c_new;
    for(int i = 0; i < m; i++) {
      if(!used_c[i]) {
        pos_new.push_back(vector<pair<int, int>>());
        used_new.push_back(vector<bool>());
        used_c_new.push_back(false);
        for(int j = 0; j < m; j++) {
          if(!used_c[j]) {
            pos_new[i].push_back(pos[i][j]);
            used_new[i].push_back(false);
            assert(!used[i][j]);
          }
        }
      }
    }
    used_c = used_c_new;
    used = used_new;
    pos = pos_new;
    vector<int> C_new;
    for(int i = 0; i < m; i++) {
      if(!used_c[i]) C_new.push_back(C[i]);
    }
    C = C_new;
  };
  while(!C.empty()) {
    const int m = C.size();
    int l = m - 1, r = 0;
    for(int i = 0; i < m; i++) {
      if(C[i] == C[m - 1]) l = min(l, i);
      if(C[i] == C[0]) r = max(r, i);
    }
    if(l > r) {
      cout << "No" << "\n";
      return true;
    }
    // color is_n and is_one
    used_c[0] = used_c[m - 1] = true;
    color(0, l, C[l]); color(0, r, C[r]);
    color(l, m - 1, C[l]); color(r, m - 1, C[r]);
    color(m - 1, m - 1 - l, C[l]), color(m - 1, m - 1 - r, C[r]);
    color(m - 1 - l, 0, C[l]); color(m - 1 - r, 0, C[r]);
    {
      int tl = l, tr = r;
      l = m - 1 - tr;
    }
    for(int i = l; i <= r; i++) {
      used_c[i] = true;
    }
    // color inner square
    for(int i = l; i <= r; i++) {
      color(l, i, C[i]); // top
      color(i, r, C[i]); // right
    }
    for(int i = r; i >= l; i--) {
      color(m - 1 - l, m - 1 - i, C[i]); // bottom
      color(m - 1 - i, m - 1 - r, C[i]); // left
    }
    // check outer rectangle
    for(int i = 1; i < l; i++) {
      int min_right = -1;
      for(int j = l; j <= r; j++) {
        if(C[m - 1 - i] == get(i, j)) {
          min_right = j;
          break;
        }
      }
      int max_left = -1;
      for(int j = r; j >= l; j--) {
        if(C[i] == get(i, j)) {
          max_left = j;
          break;
        }
      }
      if((min_right != -1 && max_left != -1) && min_right <= max_left) {
        used_c[i] = used_c[m - i - 1] = true;
        // top
        color(i, min_right, C[m - 1 - i]);
        color(i, max_left, C[i]);
        // right
        color(min_right, m - 1 - i, C[m - 1 - i]);
        color(max_left, m - 1 - i, C[i]);
        // bottom
        color(m - i - 1, m - 1 - min_right, C[m - 1 - i]);
        color(m - i - 1, m - 1 - max_left, C[i]);
        // left
        color(m - 1 - min_right, i, C[m - 1 - i]);
        color(m - 1 - max_left, i, C[i]);
      }
    }
    rebuild();
  }
  cout << "Yes" << "\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return true;
}

int main() {
  while(solve()) {}
}