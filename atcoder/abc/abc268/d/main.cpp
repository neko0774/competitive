#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(string str, int cur, unordered_set<string> &T, vector<int> &iter, vector<string> &S, int res){
  //cout << str << ' ' << cur << ' ' << res << endl;
  if(str.length()>=3&&str.length()<=16&&T.count(str)<1&&cur==S.size()){
    cout << str << endl;
    exit(0);
  }else if(cur>S.size()+1){
    return;
  }
  res-=S[iter[cur]].length();
  while((str+S[iter[cur]]).length()+res<=18){
    str += "_";
    dfs(str+S[iter[cur]], cur+1, T, iter, S, res);
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  unordered_set<string> T;
  int res = 0;
  for(int i=0;i<N;i++){
    cin >> S[i];
    res += S[i].length();
  }
  string tmp;
  for(int i=0;i<M;i++){
    cin >> tmp;
    T.insert(tmp);
  }
  string str;
  vector<int> iter;
  for(int i=0;i<N;i++){
    iter.push_back(i);
  }
  do{
    str = S[iter[0]];
    dfs(str, 1, T, iter, S, res);
  }while(next_permutation(iter.begin(), iter.end()));
  cout << -1 << endl;
}