#include <bits/stdc++.h>
using namespace std;

int main(){
  long N, M;
  cin >> N >> M;
  unordered_map<long, int> ans;
  vector<pair<long, long>> tmp;
  vector<vector<long>> chess(M+5, vector<long>(0));
  for(int i=0;i<M;i++){
    long x, y;
    cin >> x >> y;
    tmp.push_back(make_pair(x, y));
  }
  int cnt=-1;
  unordered_set<long> check;
  ans[N]++;
  sort(tmp.begin(), tmp.end());
  for(auto e: tmp){
    long x = e.first;
    long y = e.second;
    if (check.count(x)==0){
      cnt++;
      check.insert(x);
    }
    chess[cnt].push_back(y);
  }
  for(int i=0;i<M+2;i++){
    sort(chess[i].begin(), chess[i].end());
    bool exist=false, was_exist=false;
    for(long nx:chess[i]){
      if(ans.count(nx)==1){
        ans.erase(nx);
        exist = true;
        }
      else if(ans.count(nx>=2)){
        ans[nx]--;
        exist=true;
        }
      else exist=false;
      if(was_exist)ans[nx]++;
      if(ans.count(nx+1)>0)ans[nx]++;
      was_exist=exist;
    }
  }
  cout << ans.size() << endl;
}