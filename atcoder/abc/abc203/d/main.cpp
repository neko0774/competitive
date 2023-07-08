#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;


bool is_valid(int x, vector<vector<int>> A, int K, int N){
  vector<vector<int>> B(N+1, vector<int>(N+1, 0));
  for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
      if(A[i-1][j-1]>=x){B[i][j]++;}
      B[i][j] += B[i-1][j]+B[i][j-1]-B[i-1][j-1];
    }
  }
  for(int i=K;i<N+1;i++){
    for(int j=K;j<N+1;j++){
      int num=B[i][j]-B[i-K][j]-B[i][j-K]+B[i-K][j-K];
      if(num<K*K/2+1){return false;}
    }
  }
  return true;
};


int main(){
  int N, K;
  cin >> N >> K;
  vector<vector<int>> A(N, vector<int>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
    }
  }

  int ok=0, ng=INF+1;
  while(abs(ok-ng)>1){
    int m = (ok+ng)/2;
    if(is_valid(m, A, K, N)){ok = m;}
    else{ng=m;}
  }
  cout << ok << endl;
}