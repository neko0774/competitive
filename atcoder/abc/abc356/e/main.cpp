#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  ll size=1e6;
  vector<ll> C(size+1);
  unordered_map<ll, ll> count;
  for(int i=0;i<N;i++){
    cin >> A[i];
    C[A[i]]++;
    count[A[i]]++;
  }
  ll ans = 0;
  sort(A.begin(), A.end());
  for(int i=1;i<size+1;i++){
    C[i] += C[i-1];
  }
  for(auto [a, cnt]: count){
    for(int v=1;v<size/a+1;v++){
      ans += cnt*v*(C[min(size, (v+1)*a-1)]-C[v*a-1]);
    }
  }
  for(auto [a, cnt]: count){
    ans -= cnt*(cnt+1)/2;
  }
  cout << ans << endl;
}