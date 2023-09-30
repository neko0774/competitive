#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
  ll K; cin >> K;
  string S; cin >> S;
  ll ans = 0;
  for(auto s: S){
    if(s=='A') ans ^= 3;
    else if(s=='C') ans ^= 2;
    else if(s=='G') ans ^= 1;
  }
  for(int i=0;i<S.length()-K;i++){
    ans ^= 4;
  }
  cout << (ans?'S':'U') << endl;
}