#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

ll good(ll x, vector<ll> A){
  int N = A.size();
  ll ret = INF;
  for(int i=0;i<N;i++){
    ll cnt = 0;
    ll xx=x;
    bool flag = false;
    for(int j=i;j<N;j++){
      if(A[j]>=xx){
        flag = true;
        break;
      }
      cnt += xx-A[j];
      xx--;
    }
    if(flag)ret = min(ret, cnt);
  }
  return ret;
}

ll solve(){
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll ok = 0;
  ll bad = 1e15;
  while(abs(ok-bad)>1){
    ll m = (ok+bad)/2;
    //cout << ok << ' ' << bad << ' ' << m << ' ' << good(m, A) << endl;
    if(good(m, A)<=K) ok = m;
    else bad = m;
  }
  return ok;
}


int main(){
  int T;
  cin >> T;
  vector<ll> ans;
  while(T--){
    ans.push_back(solve());
  }
  for(auto a: ans) cout << a << endl;
}