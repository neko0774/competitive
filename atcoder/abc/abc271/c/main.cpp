#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<int> used(N+1);
  ll ok = 0, ng = 1e9;
  ll req = 0, rest = 0;
  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    req = mid; rest = 0;
    for(int i=0;i<N;i++) used[i]=0;
    for(ll a: A){
      if(a>mid||used[a]) rest++;
      else {used[a] = 1; req--;}
    }
    if(req<=rest/2) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}