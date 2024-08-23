#include<bits/stdc++.h>
using namespace std;

bool solve() {
  int n;
  cin >> n;
  if(n == 0) {
    return false;
  }
  long long a, b, d;
  cin >> a >> b >> d;
  const int MAX = 100;
  vector f(MAX + 1, vector<bool>(MAX + 1));
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    f[x][y] = true;
  }
  int dir_pos = 0;
  vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  tuple<int, int, int> memo[MAX + 1][MAX + 1][4];
  bool memoed[MAX + 1][MAX + 1][4];
  memset(memoed, 0, sizeof memoed);
  auto within_area = [&](int pa, int pb) -> bool {
    return 0 <= pa && pa <= MAX && 0 <= pb && pb <= MAX;
  };
  while(d > 0) {
    int da, db, p;
    da = dir[dir_pos].first;
    db = dir[dir_pos].second;
    p = dir_pos;
    // cout << a << " " << b << " " << d << endl;
    while(within_area(a + da, b + db) && f[a + da][b + db]) {
      dir_pos += 1;
      dir_pos %= 4;
      da = dir[dir_pos].first;
      db = dir[dir_pos].second;
    }
    if(!within_area(a, b)) {
      a += da * d;
      b += db * d;
      break;
    }
    if(memoed[a][b][p]) {
      int ca = a, cb = b, cp = p;
      vector<tuple<int, int, int>> v;
      while(memo[ca][cb][cp] != make_tuple(a, b, p)) {
        v.push_back(make_tuple(ca, cb, cp));
        auto [_ca, _cb, _cp] = memo[ca][cb][cp];
        ca = _ca, cb = _cb, cp = _cp;
      }
      v.push_back(make_tuple(ca, cb, cp));
      const int L = v.size();
      // cout << L << endl;
      // for(auto [f, g, h] : v) cout << f << " " << g << " " << h << endl;
      auto [_ca, _cb, _cp] = v[d % L];
      a = _ca, b = _cb;
      break;
    }
    int na, nb, np;
    na = a + da;
    nb = b + db;
    np = dir_pos;
    memoed[a][b][p] = true;
    memo[a][b][p] = make_tuple(na, nb, np);
    a = na, b = nb;
    d--;
  }
  cout << a << " " << b << endl;
  return true;
}

int main() {
  while(solve()) {}
}