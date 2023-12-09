#include<iostream>
#include<vector>
using namespace std;

int dfs(int x, int pre, int &ok, vector<vector<int>> &G){

}



int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  int a, b;
  for(int i=0;i<N;i++){
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }
  vector<bool> seen(N, false);
  int ans = 0;
  for(int i=0;i<N;i++){
    if(!seen[i]){
      int ok = 0;
      dfs(i, -1, ok);
      ans += ok;
    }
  }
}