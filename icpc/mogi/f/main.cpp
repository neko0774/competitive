#include<bits/stdc++.h>
using namespace std;



struct interval {
  int left, right, level;
};

long long hash_interval(interval I) {
  long long p = I.level * 1000000LL * 1000000LL;
  long long q = I.left * 1000000LL;
  long long r = I.right;
  return p + q + r;
}

bool solve() {
  int n;
  string s;
  cin >> n;
  if(n == 0) return false;
  cin >> s;
  const int LVL = 35;
  vector find_by_left(n, vector(LVL, vector<interval>()));
  vector find_by_right(n, vector(LVL, vector<interval>()));
  vector<interval> que;
  unordered_set<long long> us;
  for(int i = 0; i < n; i++) {
    interval I;
    I.left = I.right = i;
    I.level = s[i] - '0';
    find_by_left[I.left][I.level].push_back(I);
    find_by_right[I.right][I.level].push_back(I);
    que.push_back(I);
    us.insert(hash_interval(I));
  }
  while(!que.empty()) {
    vector<interval> nxtque;
    for(interval I : que) {
      if(I.left > 0) {
        for(interval J : find_by_right[I.left - 1][I.level]) {
          interval JI = interval{J.left, I.right, I.level + 1};
          if(us.count(hash_interval(JI))) continue;
          us.insert(hash_interval(JI));
          nxtque.push_back(JI);
          find_by_left[JI.left][JI.level].push_back(JI);
          find_by_right[JI.right][JI.level].push_back(JI);
        }
      }
      if(I.right < n - 1) {
        for(interval J : find_by_left[I.right + 1][I.level]) {
          interval IJ = interval{I.left, J.right, I.level + 1};
          if(us.count(hash_interval(IJ))) continue;
          us.insert(hash_interval(IJ));
          nxtque.push_back(IJ);
          find_by_left[IJ.left][IJ.level].push_back(IJ);
          find_by_right[IJ.right][IJ.level].push_back(IJ);
        }
      }
    }
    swap(que, nxtque);
  }
  vector<int> dp(n + 1, 0);
  for(int i = 0; i < n; i++) {
    for(int lvl = 0; lvl < LVL; lvl++) {
      for(interval I : find_by_left[i][lvl]) {
        dp[I.right + 1] = max(dp[I.right + 1], dp[i] + I.right - I.left);
      }
    }
    
  }
  cout << dp[n] << endl;
  return true;
}

int main() {
  while(solve()) {}
}