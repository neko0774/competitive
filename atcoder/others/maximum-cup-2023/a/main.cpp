#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  unordered_map<ll, ll> C;
  for(int i=0;i<N;i++){
    cin >> A[i];
    C[A[i]]++;
  }
  ll ans = 0;
  for(auto [a, b]: C){
    ans += b*(b-1)/2;
  }
  cout << ans << endl;
}
