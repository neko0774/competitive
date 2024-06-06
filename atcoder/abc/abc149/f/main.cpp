#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
#include<atcoder/modint>
using mint = atcoder::modint1000000007;


mint mod_pow(mint x, ll y){
  mint ret = 1;
  while(y>0){
    if(y&1) ret *= x;
    x *= x;
    y >>= 1;
  }
  return ret;
}


vector<int> G[1<<18];
vector<ll> cnt;
ll N;
mint ans = 0;
void dfs(int x, int par=-1){
  cnt[x]++;
  vector<ll> t;
  for(auto nx:G[x]){
    if(nx==par) continue;
    dfs(nx, x);
    cnt[x] += cnt[nx];
    t.push_back(cnt[nx]);
  }
  if(x!=0) t.push_back(N-cnt[x]);
  mint memo = mod_pow((mint)2, N-1)-1;
  for(auto g:t){
    memo += -mod_pow(mint(2), g) + 1;
  }
  ans += memo;
}

int main(){
  cin >> N;
  int A, B;
  cnt.resize(N+5, 0);
  for(int i=0;i<N-1;i++){
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  dfs(0);

  mint rev = mod_pow((mint)2, mod-2);

  ans *= mod_pow(rev, N);
  cout << ans.val() << endl;
}