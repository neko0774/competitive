#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int N;
  cin >> N;
  vector<ll> A(N), B(N+1);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<N+1;i++){
    cin >> B[i];
  }

  ll ans = 0;
  ll dif = abs(B[N]-A[0]);
  for(int i=0;i<N;i++){
    if(A[i]>B[i]) swap(A[i], B[i]);
    ans += B[i]-A[i];
    if(A[i]<=B[N]&&B[N]<=B[i]) dif = 0;
    dif = min(dif, min(abs(B[N]-A[i]), abs(B[N]-B[i])));
  }
  cout << ans + dif + 1LL << endl;
}

int main(){
  int T;
  cin >> T;
  while(T--){solve();} 
}