#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;
  ll cnt = 0;
  for(auto s:S){
    if(s=='p') cnt++;
  }
  cout << S.size()/2-cnt << endl;
}