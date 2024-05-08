#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e15;

void solve(){
  int N, K;
  cin >> N >> K;
  vector<long long> A(K, 0);
  vector<long long> T(K, 0);
  vector<long long> ans(N, INF);
  for(int i=0;i<K;i++){
    cin >> A[i];
    A[i]--;
  }
  for(int i=0;i<K;i++){
    cin >> T[i];
  }
  for(int i=0;i<K;i++){
    ans[A[i]] = T[i];
  }

  for(int i=0;i<N;i++){
    //cout << i << ' ' << ans[i] << ' ' << index << ' ' << T[index] << endl;
    if(i!=0)ans[i] = min(ans[i], ans[i-1]+1);
  }
  for(int i=N-1;i>=0;i--){
    if(i!=N-1)ans[i] = min(ans[i], ans[i+1]+1);
  }
  for(auto a: ans) cout << a << ' ';
  cout << endl;
}

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    solve();
  }  

  return 0;
}