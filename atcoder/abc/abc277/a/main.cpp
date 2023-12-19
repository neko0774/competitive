#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll N, X;
  cin >> N >> X;
  vector<ll> P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  for(int i=0;i<N;i++){
    if(P[i]==X){
      cout << 1+i << endl;
      return 0;
    }
  }

}