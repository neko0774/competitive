#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool issame(string S, string &T, long v){
  long vv=0;
  sort(S.rbegin(), S.rend());
  while(S.back()=='0'){
    vv ++;
    S.pop_back();
  }
  if(vv>v||S.size()!=T.size())return false;
  for(int i=0;i<S.size();i++){
    if(S[i]!=T[i])return false;
  }
  return true;
}

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  long v=0;
  sort(S.rbegin(), S.rend());
  while(S.back()=='0'){
    S.pop_back();
    v++;
  }
  for(long i=0;i<1e7;i++){
    long c=i*i;
    if (issame(to_string(c), S, v))ans++;
  }
  cout << ans << endl;
}