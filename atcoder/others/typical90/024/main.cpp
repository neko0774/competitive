#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
  }

  long cnt = 0;
  for(int i=0;i<N;i++){
    cnt += abs(A[i]-B[i]);
  }
  if(cnt<=K&&(K-cnt)%2==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}