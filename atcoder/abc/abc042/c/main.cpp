#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(K);
  for(int i=0;i<K;i++){
    cin >> A[i];
  }
  for(int i=N;i<N*10+10;i++){
    int v = i;
    bool ok = true;
    while(v){
      for(auto &a:A){
        if(a==v%10)ok=false;
      }
      v /= 10;
    }
    if(ok){
      cout << i << endl;
      return 0;
    }
  }
}