#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dfs(int x, vector<int> &ans, vector<vector<int>> &G){
  ans[x]++;
  for(auto nx: G[x]){
    ans[x]+=dfs(nx, ans, G);
  }
  return ans[x];
}
void countnum(int x, ll &ans, vector<int> count, vector<vector<int>> G){
  ll n = count[x]/2;
  ll v = 0;
  for(auto nx: G[x]){
    if(v+count[nx]<n){}
    countnum(nx, ans, count, G);
  }
}

void show(vector<int> A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N-1);
  for(int i=0;i<N-1;i++){
    cin >> A[i];
  }
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<N-1;i++){
    G[A[i]-1].push_back(i+1);
  }
  vector<int> count(N, 0);
  dfs(0, count, G);
  show(count);
  ll ans = 0;
  countnum(0, ans, count, G);
  cout << ans << endl;
}