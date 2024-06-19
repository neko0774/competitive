#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e10;

void solve()
{
  int N;
  cin >> N;
  priority_queue<ll> q;
  vector<pair<ll, ll>> event(N);
  for (int i = 0; i < N; i++)
  {
    cin >> event[i].first >> event[i].second;
  }
  sort(event.begin(), event.end());
  event.emplace_back(INF, INF);
  int cur = 0;
  for (auto &[l, r] : event){
    while(cur<l&&q.size()>0){
      if(-q.top()<cur){
        cout << "No" << endl;
        return;
      }
      q.pop();
      cur++;
    }
    q.push(-r);
    cur = l;
  }
  cout << "Yes" << endl;
}

int main()
{
  int T;
  cin >> T;
  while (T--) solve();
}