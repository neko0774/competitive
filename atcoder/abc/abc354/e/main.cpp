#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, int>> P;
vector<int> used;
vector<int> memo;
int situ;
int dfs(int turn){
  int ret = 0;
  if(memo[situ]!=-1) return memo[situ];
  int a=0,b = 0;
  for(auto [i, j]: P){
    if(used[i]||used[j]) continue;
    used[i] = 1;
    used[j] = 1;
    situ += 1<<i + 1<<j;
    if((dfs(turn^1))==1)a++;
    else b++;
    situ -= 1<<i + 1<<j;
    used[i] = 0;
    used[j] = 0;
  }
  if(a==0&&b==0){
    return turn^1;
  }else if(turn){
    if(a)ret = 1;
    else ret = 0;
  }else{
    if(b) ret = 0;
    else ret = 1;
  }
  memo[situ] = ret;
  return ret;
}

int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> card;
  int a, b;
  for(int i=0;i<N;i++){
    cin >> a >> b;
    card.push_back(make_pair(a, b));
  }
  used.resize(N, 0);
  memo.resize(1<<N, -1);
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      P.push_back(make_pair(i, j));
    }
  }
  cout << dfs(1) << endl;
}