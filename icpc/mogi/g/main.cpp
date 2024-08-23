#include<bits/stdc++.h>
using namespace std;

void print_queue(priority_queue<long long> que) {
  while(!que.empty()) {
    cout << que.top() << " ";
    que.pop();
  }
  cout << endl;
}

bool solve() {
  int n, k;
  cin >> n >> k;
  if(n == 0 && k == 0) return false;
  vector<long long> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<long long>> C(n + 1, vector<long long>(n + 1));
  for(int i = 0; i <= n; i++) {
    long long s = 0;
    for(int j = i; j <= n; j++) {
      s += a[j];
      C[i][j] = s * s;
    }
  }
  vector<priority_queue<long long>> dp(n + 1);
  dp[0].push(0);
  for(int i = 1; i <= n; i++) {
    vector<pair<long long, int>> used;
    priority_queue<pair<long long, int>> que;
    for(int j = 0; j < i; j++) {
      long long tp = dp[j].top();
      que.push(make_pair(C[j + 1][i] + tp, j));
      dp[j].pop();
    }
    while(!que.empty() && (int)dp[i].size() < k) {
      auto pr = que.top();
      auto [val, id] = que.top();
      used.push_back(pr);
      dp[i].push(val);
      if(!dp[id].empty()) {
        long long tp = dp[id].top();
        que.push(make_pair(C[id + 1][i] + tp, id));
        dp[id].pop();
      }
      que.pop();
    }
    while(!que.empty()) {
      auto pr = que.top();
      used.push_back(pr);
      que.pop();
    }
    for(auto pr : used) {
      int id = pr.second;
      dp[id].push(pr.first - C[id + 1][i]);
    }
    // cout << "\n" << i << " : " << endl;
    print_queue(dp[i]);
  }
  vector<long long> v;
  while(!dp[n].empty()) {
    v.push_back(dp[n].top());
    dp[n].pop();
  }
  cout << *min_element(v.begin(), v.end()) << endl;
  return true;
}

int main() {
  while(solve()) {}
}