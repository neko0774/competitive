#include <vector>
#include <iostream>
using namespace std;
#define mod 1000000007
vector<vector<long>> mult(vector<vector<long>> A, vector<vector<long>> B){
  long N = A.size();
  vector<vector<long>> ret(N, vector<long>(N, 0));
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      for(int k=0;k<N;k++){
        ret[y][x] += A[y][k]*B[k][x];
        ret[y][x] %= mod; 
      }
    }
  }
  return ret;
}


void show(vector<vector<long>> A){
  long N = A.size();
  long M = A[0].size();
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout << A[i][j] << ' ';
    }
    cout << endl; 
  }
  cout << endl;
}

int main(){
  int N;
  long long K;
  cin >> N >> K;
  vector<vector<long>> A(N, vector<long>(N, 0)), mat(N, vector<long>(N, 0));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
    }
  }
  for(int i=0;i<N;i++){
    mat[i][i] = 1;
  }
  while(K){
    if(K&1){mat = mult(mat, A);}
    A = mult(A, A);
    K >>= 1;
  }
  long ans=0;
  for(auto v: mat){
    for(auto vv:v){
      ans += vv;
      ans %= mod;
    }
  }
  cout << ans << endl;
}