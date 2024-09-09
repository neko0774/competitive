#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/segtree>
using P = pair<int, int>;
P op(P x, P y){
  if(x.first > y.first) return x;
  return y;
}
P e(){
  return make_pair(0, -1);
}

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector<P> RC(N + 2);
  RC[0] = make_pair(0, 0);
  for(int i = 0; i < N; i++){
    cin >> RC[i].first >> RC[i].second;
    RC[i].first--;
    RC[i].second--;
  }
  RC[N + 1] = make_pair(H - 1, W - 1);
  sort(RC.begin(), RC.end());
  N += 2;
  atcoder::segtree<P, op, e> seg(W);
  vector<int> prev(N, -1);
  vector<int> dp(N, 0);
  for(int i = 0; i < N; i++){
    int c = RC[i].second;
    dp[i] = seg.prod(0, c + 1).first + 1;
    prev[i] = seg.prod(0, c + 1).second;
    if(seg.get(c).first < dp[i]) seg.set(c, make_pair(dp[i], i));
  }
  cout << dp[N - 1] - 2 << endl;
  vector<char> ans(H + W - 2);
  int cur = H + W - 2;
  int lst = N - 1;
  int now;
  while(cur > 0){
    now = prev[lst];
    //cout << cur << ' ' << lst << ' ' << now << endl;
    //cout << RC[lst].first << ' ' << RC[now].first << ' ' << RC[lst].second << ' ' << RC[now].second << endl;
    for(int x = 0; x < RC[lst].first - RC[now].first; x++){
      cur--;
      ans[cur] = 'D';
    }
    for(int y = 0; y < RC[lst].second - RC[now].second; y++){
      cur--;
      ans[cur] = 'R';
    }
    lst = now;
  }
  for(char a: ans){
    cout << a;
  }
  cout << endl;
}