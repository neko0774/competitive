#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int N;
  cin >> N;
  set<pair<int, int>> st;
  vector<pair<int, int>> event(N);
  for (int i = 0; i < N; i++)
  {
    cin >> event[i].first >> event[i].second;
  }
  sort(event.begin(), event.end());
  int las = 0;
  for (auto [l, r] : event)
  {
    auto i = st.lower_bound(l);
    i--;
    while (i != st.begin())
    {
      if (i->second)
    }
    st.emplace(-r, -l);
    las = l;
  }
  int sz = q.size();
  for (int i = 0; i < sz; i++)
  {
    if (-q.top() >= las)
      q.pop(), las++, sz--;
  }
  cout << (q.size() == 0 ? "Yes" : "No") << endl;
  for (int i = 0; i < sz; i++)
  {
    cout << -q.top() << ' ';
    q.pop();
  }
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
    solve();
}