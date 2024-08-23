#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> X(1e6), C(1e6);



vector<bool> seen(1e6);
set<int> cycle;
set<int> cycles;
void dfs(int x){
  if(cycle.count(x) > 0){
    cycles.insert(x);
    return;
  }
  if(seen[x]) return;
  seen[x] = 1;
  cycle.insert(x);
  dfs(X[x]);
}

int find_cycle(int sx, set<int> &used){
  used.insert(sx);
  int cost = C[sx];
  int x = X[sx];
  while(x != sx){
    cost = min(cost, C[x]);
    x = X[x];
  }
  return cost;
}

int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> X[i];
    X[i]--;
  }
  for(int i=0;i<N;i++){
    cin >> C[i];
  }
  for(int i=0;i<N;i++){
    cycle.clear();
    if(!seen[i])dfs(i);
  }
  long ans = 0;
  set<int> used;
  for(auto x: cycles){
    if(used.count(x) > 0) continue;
    ans += find_cycle(x, used);
  }
  cout << ans << endl;
}