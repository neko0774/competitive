#include <bits/stdc++.h>
using namespace std;

void chmax(unordered_map<int, int> &x, unordered_map<int, int> xx, int num){
  
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0;i<M;i++){
    cin >> A[i];
  }
  vector<int> conv = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<unordered_map<int, int>> dp(N+1);
  for(int i=0;i<N+1;i++){
    for(auto a: A){
      int nx = i+conv[a];
      if(nx<N+1){
        chmax(dp[nx], dp[i], a);
      }
    }
  }
  vector<int> ans;
  for(int i=1;i<10;i++){
    for(int j=0;j<dp[N][i];j++){
      cout << i;
    }
  }
}