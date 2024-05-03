#include<bits/stdc++.h>
using namespace std;

bool is_end = false;

void solve() {
  int n, m;
  cin >> n >> m;
  if( n == 0 && m == 0 ) {
    is_end = true;
    return;
  }
  vector<long long> a(n), w(m);
  for( int i = 0; i < n; i++ ) {
    cin >> a[i];
  }
  for( int i = 0; i < m; i++ ) {
    cin >> w[i];
  }
  vector<long long> x = {-1, 0, 1};
  set<long long> can_make;
  int  s_max = 1;
  for( int i = 0; i < m; i++ ) {
    s_max *= 3;
  }
  for( int s = 0; s < s_max; s++ ) {
    int s_copy = s;
    long long w_sum = 0;
    for( int i = 0; i < m; i++ ) {
      w_sum += w[i]*x[s_copy%3];
      s_copy /= 3;
    }
    can_make.insert(w_sum);
  }
  vector<int> id_need;
  unordered_set<long long> can_make_us(can_make.begin(), can_make.end());
  for( int i = 0; i < n; i++ ) {
    if( !can_make_us.count(a[i]) ) {
      id_need.push_back(i);
    }
  }
  if( id_need.empty() ) {
    cout << 0 << endl;
    return;
  }
  long long inf = 1LL<<60, ans = inf;
  for( const long long &ele : can_make_us ) {
    bool ok = true;
    long long w_lack = abs(ele-a[id_need.front()]);
    for( int & id : id_need ) {
      long long pl = a[id]+w_lack;
      long long mi = a[id]-w_lack;
      if( !can_make_us.count(pl) && !can_make_us.count(mi) ) {
        ok = false;
      }
    }
    if(ok) {
      ans = min(ans, w_lack);
    }
  }
  cout << ( ans == inf ? -1 : ans ) << endl;
}

int main() {
  while(true) {
    if(is_end) break;
    solve();
  }
}