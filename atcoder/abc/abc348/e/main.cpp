#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> C;
vector<ll> S;
ll total=0;
vector<int> centre;
void dfs(int x, int par, vector<vector<int>> &G){
  S[x] = C[x];
  bool is_half = true;
  for(auto nx: G[x]){
    if(nx==par)continue;
    dfs(nx, x, G);
    if(S[nx]*2>total) is_half = false;
    S[x] += S[nx];
  }
  if((total-S[x])*2>total) is_half = false;
  if(is_half) centre.push_back(x);
  return;
}

ll memo;
ll cnt;
void dfs2(int x, int par, vector<vector<int>> &G){
  memo += C[x]*cnt;
  cnt++;
  for(auto nx:G[x]){
    if(nx==par) continue;
    dfs2(nx, x, G);
  }
  cnt--;
}


int main(){
  int N;
  cin >> N;
  ll A, B;
  C.resize(N);
  S.resize(N);
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<N-1;i++){
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    cin >> C[i];
    total += C[i];
  }
  dfs(0, -1, G);
  ll ans = 6*1e18;
  for(auto x: centre){
    cnt = 0;
    memo = 0;
    dfs2(x, -1, G);
    ans = min(ans, memo);
  }
  cout << ans << endl;
}