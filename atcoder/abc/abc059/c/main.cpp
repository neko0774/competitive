#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> A, int N){
  ll sum = A[0];
  ll ans = 0;
  for(int i=1;i<N;i++){
    if(sum*(sum+A[i])>=0){
      ll n;
      if(sum>0)n = -1-sum;
      else n = 1-sum;
      ans += abs(n-A[i]);
      sum += n;
    }else{
      sum += A[i];
    }
  }
  return ans;
}
int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll ans = 1e18;
  if(A[0]>0)
}