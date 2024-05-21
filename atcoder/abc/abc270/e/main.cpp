#include <bits/stdc++.h>
using namespace std;

int main(){
  long N, K;
  cin >> N >> K;
  vector<long long> A(N, 0);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  long long ok = 0, ng = 1e12;
  long long cnt;
  while(abs(ok-ng)>1){
    long long mid = (ok+ng)/2;
    cnt = 0;
    for(int i=0;i<N;i++){
      if(A[i]>=mid) cnt += mid;
      else cnt += A[i];
    }
    if(cnt<=K) ok = mid;
    else ng = mid;
  }
  long long res = K;
  for(int i=0;i<N;i++){
    if(A[i]>=ok){
      A[i] -= ok;
      res -= ok;
    }else{
      res -= A[i];
      A[i] = 0;
    }
  }
  for(int i=0;i<N;i++){
    if(res&&A[i]>0){
      A[i]--;res--;
    }
  }
  for(auto a: A)cout << a << ' ';
  cout << endl;
}