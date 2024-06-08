#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int N;
  cin >> N;
  priority_queue<int> st;
  vector<pair<int, int>> event(N);
  for (int i = 0; i < N; i++)
  {
    cin >> event[i].first >> event[i].second;
  }
  sort(event.begin(), event.end());
  int las = event[0].first;
  for (auto &[l, r] : event)
  {
    while (l - las > 0 && st.size() > 0 && -st.top() >= l)
    {
      las++;
      st.pop();
    }
    st.emplace(-r - 1);
    las = l;
  }
  while (-st.top() > las)
    st.pop(), las++;
  cout << (st.size() == 0 ? "Yes" : "No") << endl;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
    solve();
}