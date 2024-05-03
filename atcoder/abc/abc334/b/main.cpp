#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll A, M, L, R;
  cin >> A >> M >> L >> R;
  ll k;
  if(L-A>0)k = (L-A+M-1)/M;
  else k = (L-A)/M;
  ll first = A+k*M-L;
  ll ans = max((R-L+1-first+M-1)/M, 0ll);
  cout << ans << endl;
}