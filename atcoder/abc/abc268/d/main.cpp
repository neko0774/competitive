#include <bits/stdc++.h>
using namespace std;
#define ll long long



void dfs(int cur, string ans, int res, vector<string> &S, unordered_set<string> &T, vector<int>& iter){
  ans += S[iter[cur]];
  if(cur==S.size()-1){
    if(T.count(ans)==0&&ans.length()>=3&&ans.length()<=16){
      cout << ans << endl;
      exit(0);
    }
    return;
  }
  ans += '_';
  dfs(cur+1, ans, res, S, T, iter);
  while(res>0){
    dfs(cur+1, ans, res, S, T, iter);
    ans += '_'; 
    res--;
  }
  dfs(cur+1, ans, res, S, T, iter);
  return;
}


int main(){
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  int len = 0;
  for(int i=0;i<N;i++){
    cin >> S[i];
    len += S[i].length()+1;
  }
  unordered_set<string> T;
  string tmp;
  for(int i=0;i<M;i++){
    cin >> tmp;
    T.insert(tmp);
  }
  vector<int> iter;
  for(int i=0;i<N;i++){
    iter.push_back(i);
  }
  do{
    dfs(0, "", 17-len, S, T, iter);
  }while(next_permutation(iter.begin(), iter.end()));
  cout << -1 << endl;
}