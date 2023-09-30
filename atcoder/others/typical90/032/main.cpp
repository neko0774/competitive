#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void dfs(int &ans, vector<vector<int>> &A, unordered_set<int> &ppl, int N, int time, unordered_set<int> &used, int x){
  if(time>=ans)return;
  if(used.size()==N){
    ans = min(ans, time);
    return;
  }
  for(int i=0;i<N;i++){
    if(!used.count(i)&!ppl.count(15*i+x)&!ppl.count(15*x+i)){
      used.insert(i);
      dfs(ans, A, ppl, N, time+A[i][used.size()-1], used, i);
      used.erase(i);
    }
  } 
}

int main(){
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N, 0));
  for(int j=0;j<N;j++){
    for(int i=0;i<N;i++){
      cin >> A[j][i];
    }
  }
  int M;
  cin >> M;
  unordered_set<int> ppl; 
  for(int i=0;i<M;i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    ppl.insert(A*15+B);
    ppl.insert(B*15+A);
  }
  int ans = 1e9;
  unordered_set<int> used;
  dfs(ans, A, ppl, N, 0, used, -1);
  if(ans==(int)1e9){cout << -1 << endl;}
  else cout << ans << endl;
}