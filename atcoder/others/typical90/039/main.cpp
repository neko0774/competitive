#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<ll> &cnt, vector<vector<int>> &G, int x, int pre){
  cnt[x]++;
  for(auto nx: G[x]){
    if(nx!=pre){
      dfs(cnt, G, nx, x);
      cnt[x] += cnt[nx];
    }
  }
}



int main(){
  int N;
  cin >> N;
  int a, b;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<N-1;i++){
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<ll> cnt(N, 0);
  ll ans = 0;
  dfs(cnt, G, 0, -1);
  for(auto x: cnt){
    ans += x*(N-x);
  }
  cout << ans << endl;
}