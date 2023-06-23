#include <bits/stdc++.h>
using namespace std;

int main(){
  int A;
  cin >> A;
  string ans="NO";
  for(int i=0;i<4;i++){
    int tmp;
    cin >> tmp;
    if(tmp==A){ans="YES";}
    A = tmp;
  }
  cout << ans << endl;
}