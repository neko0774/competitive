#include <bits/stdc++.h>
using namespace std;
vector<vector<unsigned int>> calc(vector<vector<unsigned int>> A, vector<vector<unsigned int>> B){
  unsigned int N = A.size();
  unsigned int M = B.size();
  unsigned int K = B[0].size();
  vector<vector<unsigned int>> ret(N, vector<unsigned int>(K,0));
  for(int y=0;y<N;y++){
    for(int x=0;x<K;x++){
      for(int k=0;k<M;k++){
        ret[y][x] ^=  A[y][k]&B[k][x];
      }
    }
  }
  return ret;
}
vector<vector<unsigned int>> expo(vector<vector<unsigned int>> A, long K){
  unsigned int N = A.size();
  vector<vector<unsigned int>> ret(N, vector<unsigned int>(N, 0));
  for(int i=0;i<N;i++){//creating unit matrix
    ret[i][i] = -1;
  }
  while(K){
    if(K&1){
      ret = calc(ret, A);
    }
    A = calc(A, A);
    K >>=1;
  }
  return ret;
}

void show_mat(vector<vector<unsigned int>> A){
  int N = A.size();
  int B = A[0].size();
  for(int i=0;i<N;i++){
    for(int j=0;j<B;j++){
      cout << A[i][j] << ' ';
    }
    cout << endl;
  }
}


int main(){
  long K, M;
  cin >> K >> M;
  vector<unsigned int> A(K), C(K);
  for(long i=0;i<K;i++){
    cin >> A[i];
  }
  for(long i=0;i<K;i++){
    cin >> C[i];
  }
  if(M-K<=0){cout << A[M-1] << endl;return 0;}
  vector<vector<unsigned int>> mat(K, vector<unsigned int>(K, 0));
  for(int x=0;x<K;x++){
    mat[0][x] = C[x];
  }
  for(int x=1;x<K;x++){
    mat[x][x-1] = -1;
  }
  //show_mat(mat);
  mat = expo(mat, M-K);
  unsigned int ans = 0;
  for(int i=0;i<K;i++){
    ans ^= mat[0][i]&A[K-i-1];  
  }
  cout << ans << endl;
}