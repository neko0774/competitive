#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int M;
  cin >> M;
  vector<vector<int>> G(9);
  int u, v;
  for(int i=0;i<M;i++){
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> P(8);
  for(int i=0;i<8;i++){
    cin >> P[i];
    P[i]--;
  }
  queue<string> q;
  string s;
  for(auto p: P)s += to_string(p);
  unordered_map<string, int> dp;
  dp[s] = 0;
  q.push(s);
  while(!q.empty()){
    string situation = q.front();
    q.pop();
    int cur = 45-9;
    for(auto s:situation)cur-=s-'0';
    for(int ng: G[cur]){
      string ncur=situation;
      for(int i=0;i<situation.length();i++){
        if(situation[i]-'0'==ng){ncur[i]=char(cur+48);break;}
      }
      if(dp.count(ncur)==0){
        dp[ncur] = dp[situation]+1;
        q.push(ncur);
      }
    }
  }
  cout << (dp.count("01234567")>=1?dp["01234567"]:-1)<<endl;
}