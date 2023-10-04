#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  bool pre = true, tail = true;
  for(int i=0;i<N;i++){
    if(S[i]!=T[i])pre = false;
  }
  for(int i=0;i<N;i++){
    if(S[N-i-1]!=T[M-i-1])tail = false;
  }
  if(pre&&tail) cout << 0 << endl;
  else if(pre) cout << 1 << endl;
  else if(tail) cout << 2 << endl;
  else cout << 3 << endl;

}