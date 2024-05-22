#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
  ll N, A, B;
  cin >> N >> A >> B;
  ll lcp = A*B/gcd(A, B);
  ll ans = N*(N+1)/2;
  ll a = N/A, b = N/B, l = N/lcp;
  ans -= B*(b*(b+1)/2);
  ans -= A*(a*(a+1)/2);
  ans += lcp*(l*(l+1)/2);
  cout << ans << endl;
}