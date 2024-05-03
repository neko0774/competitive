#include<bits/stdc++.h>
using namespace std;

bool is_end = false;

void solve() {
  int H, W;
  cin >> H >> W;
  if(H == 0 && W == 0) {
    is_end = true;
    return;
  }
  vector<string> S(H);
  for(int i = 0; i < H; i++) {
    cin >> S[i];
  }
  map<vector<string>, int> memo;
  auto dfs = [&](auto dfs) -> int {
    if(memo.count(S)) {
      return memo[S];
    }
    // 辞書順最小の座標を見つける
    int r = -1, c = -1;
    for(int i = 0; i < H && r == -1; i++) {
      for(int j = 0; j < W && r == -1; j++) {
        if(S[i][j] == '.') {
          r = i, c = j;
        }
      }
    }
    // cout << r+ 1 << " " << c+1 << endl;
    // for(string &_s : S) cout << _s << endl;
    // cout << endl;
    // 終了条件
    if(r == -1 && c == -1) {
      memo[S] = 1;
      return 1;
    }
    int ret = 0;
    if(c + 1 < W && r + 1 < H) { // type 01
      if(S[r][c + 1] == '.' && S[r + 1][c] == '.') {
        S[r][c] = S[r][c + 1] = S[r + 1][c] = '#';
        ret += dfs(dfs);
        S[r][c] = S[r][c + 1] = S[r + 1][c] = '.';
      }
    }
    if(c + 1 < W && r + 1 < H) { // type 02
      if(S[r][c + 1] == '.' && S[r + 1][c + 1] == '.') {
        S[r][c] = S[r][c + 1] = S[r + 1][c + 1] = '#';
        ret += dfs(dfs);
        S[r][c] = S[r][c + 1] = S[r + 1][c + 1] = '.';
      }
    }
    if(c + 1 < W && r + 1 < H) { // type 03
      if(S[r + 1][c] == '.' && S[r + 1][c + 1] == '.') {
        S[r][c] = S[r + 1][c] = S[r + 1][c + 1] = '#';
        ret += dfs(dfs);
        S[r][c] = S[r + 1][c] = S[r + 1][c + 1] = '.';
      }
    }
    if(c - 1 >= 0 && r + 1 < H) { // type 04
      if(S[r + 1][c] == '.' && S[r + 1][c - 1] == '.') {
        S[r][c] = S[r + 1][c] = S[r + 1][c - 1] = '#';
        ret += dfs(dfs);
        S[r][c] = S[r + 1][c] = S[r + 1][c - 1] = '.';
      }
    }
    memo[S] = ret;
    return ret;
  };
  cout << dfs(dfs) << endl;
}

int main(){
  while(!is_end) { solve(); }
}