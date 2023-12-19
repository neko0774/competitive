#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll N, L, R;
  cin >> N >> L >> R;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<ll> ans(N);
  for(int i=0;i<N;i++){
    if(L<=A[i]&&A[i]<=R) ans[i] = A[i];
    else if(abs(L-A[i])>abs(R-A[i])) ans[i] = R;
    else ans[i] = L;
  }
  for(auto l: ans)cout << l << ' ';
  cout << endl;
}