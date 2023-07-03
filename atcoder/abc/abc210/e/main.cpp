#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> A(M);

  for(int i=0;i<M;i++){
    int a,c; cin >> a >> c;
    A[i]=make_pair(c, a);
  }
  sort(A.begin(), A.end());
  long long ans=0;
  int n=N;
  for(int i=0;i<M;i++){
    int a = A[i].second, c=A[i].first;
    int d = gcd(n, a);
    ans += (long long) c*(n-d);
    n = d;
  }
  if (n>1){cout << -1 << '\n';}
  else {cout << ans << '\n';}
}