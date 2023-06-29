#include <bits/stdc++.h>
using namespace std;
bool solve() {
  int n;
  double r;
  cin >> r >> n;
  if( abs(r) < 1e-3 ) return false;
  vector<pair<int, int>> event;
  for( int i = 0; i < n; i++ ) {
    int xl, xr, h;
    cin >> xl >> xr >> h;
    event.push_back(make_pair(xl, -h));
    event.push_back(make_pair(xr, h));
  }
  sort(event.begin(), event.end());
  vector<pair<int, int>> boundary;
  multiset<int> Sh;
  Sh.insert(0);
  boundary.push_back(make_pair(-40, 0));
  for( int i = 0; i < event.size(); i++ ) {
    int h_pre = *Sh.rbegin();
    auto [x, h] = event[i];
    if( h > 0 ) {
      Sh.erase(Sh.find(h));
    }else {
      Sh.insert(-h);
    }
    int h_cur = *Sh.rbegin();
    boundary.push_back(make_pair(x, h_pre));
    boundary.push_back(make_pair(x, h_cur));
  }
  boundary.push_back(make_pair(40, 0));
  double t = 0, step = 0.0001;
  auto dist = [&](double xl, double yl, double xr, double yr) -> double {
    if( xl > xr ) swap(xl, xr);
    if( yl > yr ) swap(yl, yr);
    if( xl == xr ) {
      double dy = max({0.0, yl-(-r+t), (-r+t)-yr});
      return hypot(xl, dy);
    }else {
      double dx = max({0.0, xl, -xr});
      return hypot(dx, yl-(-r+t));
    }
  };
  for( ; ; t+=step ) {
    bool is_covered = true;
    for( int i = 0; i < boundary.size()-1; i++ ) {
      auto [xl, yl] = boundary[i];
      auto [xr, yr] = boundary[i+1];
      if( dist(xl, yl, xr, yr) < r ) is_covered = false;
    }
    if( !is_covered ) break;
  }
  cout << fixed << setprecision(8) << t-step << endl;
  return true;
}
int main() {
  while( solve() ) {}
}