#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  ll z=0,o=0;  
  ll ans = 0;
  ll tmp;
  for(auto s:S){
    if (s=='0'){
      o = z+o;
      z = 1;
    }else{
      tmp = z;
      z = o;
      o = tmp+1;
    }
    ans += o;
  }
  cout << ans << endl;
}