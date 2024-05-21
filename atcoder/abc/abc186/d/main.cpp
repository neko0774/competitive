#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  long long sum = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    sum += A[i];
  }
  sort(A.rbegin(), A.rend());
  long long ans = 0;
  for(int i=0;i<N;i++){
    sum -= A[i];
    ans += A[i]*(N-1-i) - sum;
  }
  cout << ans << endl;
}