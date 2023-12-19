#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  string S;
  cin >> S;

  for(int i=0;i<S.length();i++){
    if(S[i]==',')S[i] = ' ';
  }
  cout << S << endl;
}