#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N, H, X;
  cin >> N >> H >> X;
  ll P;
  for(int i=0;i<N;i++){
    cin >> P;
    if(P+H>=X){
      cout << i+1 << endl;
      return 0;
    }
  }

}