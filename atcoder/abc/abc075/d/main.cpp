#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  vector<ll> X(N), Y(N);
  for(int i = 0;i < N; i++){
    cin >> X[i] >> Y[i];
  }
  ll ans = LLONG_MAX;
  for(ll l: X){
    for(ll r: X){
      for(ll d: Y){
        for(ll u: Y){
          if(l > r || d > u) continue;
          int count = 0;
          for(int i = 0; i < N; i++){
            if(l <= X[i] && X[i] <= r && d <= Y[i] && Y[i] <= u) count++;
          }
          if(count >= K){
            ans = min(ans, (r - l) * (u - d));
          }
        }
      }
    }
  }
  cout << ans << endl;
}