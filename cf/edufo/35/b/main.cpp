#include<bits/stdc++.h>
using namespace std;


bool good(long x, int A, int B, int N){
  if(x>A||x>B) return false;
  return A/x + B/x >= N;
}

int main(){
  int N, A, B;
  cin >> N >> A >> B;

  long ok = 0, ng = 1e9;  
  while(abs(ok-ng)>1){
    long mid = (ok+ng)/2;
    if(good(mid, A, B, N)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}