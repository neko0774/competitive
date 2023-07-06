#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int n,m;
  cin>>n >>m;
  if(n==0 && m==0)return 0;
  vector<int> a(m),b(m);
  for(int i=0; i<m;i++) {
    cin >> a[i] >> b[i];
    if( a[i] > b[i] ) swap(a[i], b[i]);
  }
  int BASE = 10000;
  auto gen_pair = [&](int x, int y) -> vector<int> {
    vector<int> ret = {0, x, y, x*BASE+y, y*BASE+x};
    return ret;
  };
  vector<vector<int>> G(n+1, vector<int>());
  for( int i = 0; i < m; i++ ) {
    if( a[i] > 0 && b[i] > 0 ) {
      G[a[i]].push_back(i);
      G[b[i]].push_back(i);
    }
  }
  int ans = 0;
  for( int l = 0; l < m; l++ ) {
    bool ok = true;
    vector<int> cnt_need(m, 2);
    vector<bool> popped(n+1, false);
    unordered_set<int> medicine, invalid;
    auto INSERT = [&](int x, int y) -> void {
      vector<int> p = gen_pair(x, y);
      for( int _p : p ) invalid.insert(_p);
    };
    for( int x = 1; x <= n; x++ ) {
      medicine.insert(x);
    }
    for( int r = l; r < m; r++ ) {
      if( cnt_need[r] == 0 ) ok = false;
      if( a[r] < 0 && b[r] < 0 && a[r] != b[r] ) {
        INSERT(-a[r], -b[r]);
      }
      if( a[r] < 0 && b[r] > 0 && a[r] != -b[r] ) {
        INSERT(-a[r], 0);
      }
      if( a[r] < 0 && b[r] < 0 && a[r] == b[r] ) {
        medicine.erase(-a[r]);
        if( !popped[-a[r]] ) {
          popped[-a[r]] = true;
          for( int id : G[-a[r]] ) {
            cnt_need[id]--;
            if( l <= id && id <= r && cnt_need[id] == 0 ) ok = false;
          }
        }
        if( !popped[-b[r]] ) {
          popped[-b[r]] = true;
          for( int id : G[-b[r]] ) {
            cnt_need[id]--;
            if( l <= id && id <= r && cnt_need[id] == 0 ) ok = false;
          }
        }
        
      }
      if( medicine.size() <= 2 ) {
          vector<int> vm(medicine.begin(), medicine.end());
          if( vm.size() == 2 && invalid.count(vm[0]*BASE+vm[1]) ) ok = false;
          if( vm.size() == 1 && invalid.count(vm[0]) ) ok = false;
          if( vm.size() == 0 ) ok = false;
        }
      if(ok) {
        ans = max(ans, r-l+1);
      }else {
        break;
      }
    }
  }
  cout << ans << endl;
  return 1;
}

int main(){
  while(solve()){}
}