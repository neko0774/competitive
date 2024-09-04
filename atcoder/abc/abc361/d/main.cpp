#include <bits/stdc++.h>
using namespace std;
#define ll long long
void sa(int i, int j, string &S){
  swap(S[i], S[j]);
  swap(S[i+1], S[j+1]);
}

bool same(string &S, string &T){
  for(int i=0;i<N+2;i++){
    if(S[i]!=T[i]) return false;
  }
  return true;
}

int main(){
  cin >> N;
  string S, T;
  cin >> S >> T;
  S.push_back('.');
  S.push_back('.');
  T.push_back('.');
  T.push_back('.');
  queue<string> q;
  q.push(S);
  while(!q.empty()){
    
  }
  if(ans == inf)cout << -1 << endl;
  else cout << ans << endl;
}