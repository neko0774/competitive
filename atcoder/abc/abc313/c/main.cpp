#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  vector<long> A(N);
  long v=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    v+=A[i];
  }
  if(v%N==0){
    long ave = v/N;
    long p=0;
    long m=0;
    for(auto a:A){
      if(a>ave) p+=ave-a;
      else m+=a-ave;
    }
    cout << (max(m, p)+1)/2 << endl;
  }
  else{
    long p = 0;
    long m = 0;
    long ave = v/N;
    long avee = ave+1;
    for(auto a: A){
      if(a>=ave) p+=min(a-ave, a-avee);
      else m+=min(ave-a, avee-a);
    }
    cout << max(p, m) << endl;
  }
  
}