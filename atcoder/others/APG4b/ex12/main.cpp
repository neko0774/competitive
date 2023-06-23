#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int ans=1;
  cin >> S;
  for (int i=1; i<S.length(); i+=2){
    if (S[i]=='+'){ans++;}
    else{ans--;}
  }
  cout << ans << endl;
}