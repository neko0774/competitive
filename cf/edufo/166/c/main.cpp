#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(){
  int N, M;
  cin >> N >> M;
  int S = N+M+1;
  vector<ll> A(S), B(S);
  for(int i=0;i<S;i++){
    cin >> A[i];
  }
  ll su = 0;
  for(int i=0;i<S;i++){
    cin >> B[i];
    su += B[i];
  }

  vector<pair<ll, int>> dif(S, pair<ll, int>());
  for(int i=0;i<S;i++){
    dif[i].first = A[i]-B[i];
    dif[i].second = i;
  }
  sort(dif.rbegin(), dif.rend());
  vector<ll> ans(S);
  ll prog=0, test=0;
  for(int i=0;i<N;i++){
    prog += dif[i].first;
  }
  for(int i=N+1;i<S;i++){
    test += dif[i].first;
  }
  //ans[dif[N].second] = prog + test + su - B[dif[N].second];
  for(int i=0;i<S;i++){
    ans[dif[i].second] = profil + test + su - B[dif[i].second] + dif[N].first - dif[i].first;
  }
  for(auto s: ans) cout << s << ' ';
  return 0;
}

int main(){
  int T;
  cin >> T;
  while(T--){solve();} 
}