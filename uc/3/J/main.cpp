#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int n = N / 2;
  const int TARGET = 1000000000;
  vector<pair<int, int>> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());
  mt19937 ra(time(NULL));
  int S = 0;
  vector<int> p(n);
  time_t tbegin_all = clock();
  while(true) {
    unordered_set<int> p_init;
    while(int(p_init.size()) < n) {
      p_init.insert(ra() % N);
    }
    S = 0;
    p = vector<int>(p_init.begin(), p_init.end());
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
      S += A[p[i]].first;
    }
    time_t tbegin = clock();
    while(S != TARGET) {
      time_t tend = clock();
      if(((double)tend - (double)tbegin) / (double)CLOCKS_PER_SEC > 0.18) break;
      if(S > TARGET) {
        int i = ra() % n;
        if(i == 0 && p[i] == 0) continue;
        if(i != 0 && p[i] - 1 == p[i - 1]) continue;
        S -= A[p[i]].first;
        S += A[p[i] - 1].first;
        p[i]--;
      }else {
        int i = ra() % n;
        if(i == n - 1 && p[i] == N - 1) continue;
        if(i != n - 1 && p[i] + 1 == p[i + 1]) continue;
        S -= A[p[i]].first;
        S += A[p[i] + 1].first;
        p[i]++;
      }
    }
    if(S == TARGET) {
      cout << n;
      for(int i = 0; i < n; i++) {
        cout << " " << A[p[i]].second + 1 ;
      }
      cout << endl;
      break;
    }
    time_t tend_all = clock();
    if(((double)tend_all - (double)tbegin_all) / (double)CLOCKS_PER_SEC > 1.9) break;
  }
  time_t tend = clock();
  cout << tend-tbegin_all << endl;
}