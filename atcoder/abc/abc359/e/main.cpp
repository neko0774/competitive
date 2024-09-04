#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e12;

int main(){
  int N;
  cin >> N;
  vector<ll> H(N);
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  stack<vector<ll>> last_h;
  last_h.push({inf, -1LL, 0LL});
  for(int i=0;i<N;i++){
    while(!last_h.empty()&&last_h.top()[0]<=H[i]){
      last_h.pop();
    }

    ll cost = last_h.top()[2];
    ll l = last_h.top()[1];

    ll ans = cost + ((ll)i - l) * H[i];
    cout << ans + 1 << ' ';
    last_h.push({H[i], (ll)i, ans});
  }
  cout << endl;
  return 0;
}