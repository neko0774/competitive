#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15;

void show(vector<ll> A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}
vector<ll> LIS(vector<ll> A){
  ll N = A.size();
  vector<ll> ret(N, 0);
  vector<ll> lis(N, INF);
  for(int i=0;i<N;i++){
    if(A[i]>lis[i]){
      lis[i] = A[i];
      ret[i] = i+1;
      }
    else{
      ll t = lower_bound(lis.begin(), lis.end(), A[i])-lis.begin();
      lis[t] = A[i];
      ret[i] = t+1;
    }
  }
  return ret;
}


int main(){
  int N;cin >> N;
  vector<ll> A(N), B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    B[N-i-1] = A[i];
  }
  vector<ll> inc = LIS(A), dec = LIS(B);

  ll ans = 0;
  for(int i=0;i<N;i++){
    ans = max(ans, inc[i]+dec[N-i-1]);
  }
  cout << ans-1 << endl;
}