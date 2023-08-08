#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<vector<int>> &G, long cnt, vector<int> &goal, unordered_set<int> &seen){
  if(seen.count(s)>=1) return;
  if(G[s].size()==0){goal.push_back(s);}
  if(cnt>G.size()){goal.push_back(-1);return;}
  seen.insert(s);
  for(auto nx: G[s]){
    cnt++;
    dfs(nx, G, cnt, goal, seen);
  }
}

void show(vector<int> A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}

int min(vector<int> A){
  int v = 1e9+1;
  for(auto a: A) v = min(v, a);
  return v;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<M;i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    G[B].push_back(A);
  }
  int ans=-1;
  for(int i=0;i<N;i++){
    vector<int> check;
    unordered_set<int> seen;
    dfs(i, G, 0, check, seen);
    //cout << i << ' ';
    //show(check);
    if(check.size()>1||min(check)==-1||(ans!=-1&&ans!=check[0])){
      cout << -1 << endl;
      return 0;
    }
    ans = check[0];
  }
  cout << ans+1 << endl;
}