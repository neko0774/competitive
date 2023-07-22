#include <bits/stdc++.h>
using namespace std;

int main(){
  long N, M;
  cin >> N >> M;
  map<long, vector<long>> chess;
  for(int i=0;i<M;i++){
    long x,y;
    cin >> x >> y;
    chess[x].push_back(y);
  }
  unordered_set<long> ans;
  ans.insert(N);
  for(auto p:chess){
    unordered_set<long> ok, ng;
    for(long nx:p.second){
      if(ans.count(nx-1)||ans.count(nx+1)) ok.insert(nx);
      else ng.insert(nx);
    }
    for(auto nx: ng) ans.erase(nx);
    for(auto nx: ok) ans.insert(nx);
  }
  cout << ans.size() << endl;
}