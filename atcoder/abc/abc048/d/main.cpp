#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;

  int ans = 0;
  if(S[0]==*S.rbegin())ans++;
  if(S.length()%2==0)ans++;
  cout << ((ans%2==0)?"First":"Second") << endl;
}