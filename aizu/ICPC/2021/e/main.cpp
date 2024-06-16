#include<bits/stdc++.h>
using namespace std;
using T = tuple<int, long long, bool, int>;
bool solve(){
  int N, P, Q;
  cin >> N >> P >> Q;
  if(N == 0) return 0;

  vector walk(N, vector<pair<int, long long>>());
  vector car(N, vector<pair<int, long long>>());
  for(int i = 0; i < P; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    walk[a].push_back(make_pair(b, c));
    walk[b].push_back(make_pair(a, c));
  }
  for(int i = 0; i < Q; i++) {
    int d, e, f;
    cin >> d >> e >> f;
    d--, e--;
    car[d].push_back(make_pair(e, f));
    car[e].push_back(make_pair(d, f));
  }

  const int BOUND = 40;
  const long long INF = 1LL << 59;
  // 回数、時間、フラグ、番号
  auto comp=[](const T &p, const T &q)->bool {
    auto[cp, dp, fp, ip] = p;
    auto[cq, dq, fq, iq] = q;
    if (cp > BOUND || cq > BOUND) {
      if(cp == cq) return dp > dq;
      else return cp > cq;
    }
    long long CP = (1LL << cp) - 1;
    long long CQ = (1LL << cq) - 1;
    return dp + CP > dq + CQ;
  };
  const T DP_INIT = T{1000000, 0, 0, -1};
  priority_queue<T, vector<T>, function<bool(T, T)>> que(comp);
  vector dp_small(N, vector(BOUND + 1, vector<T>(2, DP_INIT)));
  vector dp_large(N, vector<T>(2, DP_INIT));

  dp_small[0][0][0] = T{0, 0, 0, 0};
  que.push(T{0, 0, 0, 0});
  int attempt = 0;
  while(!que.empty()) {
    auto tpl = que.top();
    auto [ci, di, fi, i] = tpl;
    // assert(0 <= i && i < N);
    // assert(attempt++ <= 10);
    // cout << ci << " " << di << " " << fi << " " << i + 1 << endl;
    que.pop();
    if(ci > BOUND) {
      if(comp(tpl, dp_large[i][fi])) continue;
    }else {
      if(comp(tpl, dp_small[i][ci][fi])) continue;
    }
    if(fi) {
      // car -> walk
      for(const auto [to, cost] : walk[i]) {
        T nxt = T{ci, di + cost, 0, to};
        if(ci > BOUND && comp(dp_large[to][0], nxt)) {
          dp_large[to][0] = nxt;
          que.push(nxt);
        }else if(ci <= BOUND && comp(dp_small[to][ci][0], nxt)) {
          dp_small[to][ci][0] = nxt;
          que.push(nxt);
        }
      }
      // car -> car
      for(const auto [to, cost] : car[i]) {
        T nxt = T{ci, di + cost, 1, to};
        if(ci > BOUND && comp(dp_large[to][1], nxt)) {
          dp_large[to][1] = nxt;
          que.push(nxt);
        }else if(ci <= BOUND && comp(dp_small[to][ci][1], nxt)) {
          dp_small[to][ci][1] = nxt;
          que.push(nxt);
        }
      } 
    }else {
      // walk -> walk
      for(const auto [to, cost] : walk[i]) {
        T nxt = T{ci, di + cost, 0, to};
        if(ci > BOUND && comp(dp_large[to][0], nxt)) {
          dp_large[to][0] = nxt;
          que.push(nxt);
        }else if(ci <= BOUND && comp(dp_small[to][ci][0], nxt)) {
          dp_small[to][ci][0] = nxt;
          que.push(nxt);
        }
      }
      // walk -> car
      for(const auto [to, cost] : car[i]) {
        T nxt = T{ci + 1, di + cost, 1, to};
        if(ci + 1 > BOUND && comp(dp_large[to][1], nxt)) {
          dp_large[to][1] = nxt;
          que.push(nxt);
        }else if(ci + 1 <= BOUND && comp(dp_small[to][ci + 1][1], nxt)) {
          // cout << i + 1 << " " << to + 1 << " " << di + cost << endl;
          dp_small[to][ci + 1][1] = nxt;
          que.push(nxt);
        }
      } 
    }
  }

  priority_queue<T, vector<T>, function<bool(T, T)>> ans(comp);
  {
    auto [c, d, f, i] = dp_large[N - 1][0];
    ans.push(T{c, d, f, i});
  }
  {
    auto [c, d, f, i] = dp_large[N - 1][1];
    ans.push(T{c, d, f, i});
  }
  for(int cn = 0; cn <= BOUND; cn++) {
    for(int fn = 0; fn <= 1; fn++) {
      auto [c, d, f, i] = dp_small[N - 1][cn][fn];
      ans.push(T{c, d, f, i});
    }
  }

  const long long MOD = 1000000007;
  auto [copt, dopt, fopt, opt] = ans.top();

  if(ans.top() == DP_INIT) {
    cout << -1 << endl;
    return 1;
  }

  // 2 ^ {copt + 1} の計算
  long long pt = 1;
  for(int i = 0; i < copt; i++) pt = pt * 2 % MOD;

  cout << (pt - 1 + dopt) % MOD << endl;
  return 1; 
}


int main(){
  while(solve()){}
}