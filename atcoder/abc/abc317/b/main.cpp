#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N;
  cin >> N;
  vector<ll> P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  sort(P.begin(), P.end());
  for(int i=0;i<N-1;i++){
    if(P[i]+1ll!=P[i+1]){
      cout << P[i]+1 << endl;
      break;
    }
  }
}