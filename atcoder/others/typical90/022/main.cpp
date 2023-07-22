#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A, B, C;
  cin >> A >> B >> C;
  long x = gcd(A, gcd(B, C));
  long ans = A/x+B/x+C/x-3;
  cout << ans << '\n';
}