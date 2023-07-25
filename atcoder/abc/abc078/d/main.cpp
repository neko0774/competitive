#include <iostream>

using namespace std;

int main(){
  int N, Z, W;
  cin >> N >> Z >> W;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
  dp[0][0] = W;

}