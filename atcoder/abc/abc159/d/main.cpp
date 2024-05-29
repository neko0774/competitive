#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  ll ans = 0;
  vector<ll> cal(N, 0);
  for(int i=0;i<N;i++){
    cin >> A[i];
    A[i]--;
    cal[A[i]]++;
  }
  for(int i=0;i<N;i++){
    if(cal[i]>0) ans += cal[i]*(cal[i]-1)/2;
  }
  for(int i: A){
    ll m = 0;
    if(cal[i]>=2) m = -cal[i]*(cal[i]-1)/2 + (cal[i]-1)*(cal[i]-2)/2;
    else if(cal[i]>=1) m -= cal[i]*(cal[i]-1)/2;
    //cout << m << ' ';
    cout << ans + m << endl;
  }
}