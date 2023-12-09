#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;
  //aba or aa
  int N = S.length();
  for(int i=0;i<N;i++){
    if(i+1<N&&S[i]==S[i+1]){
      cout << i+1 << ' ' << i+2 << endl;
      return 0;
    }
    else if(i+2<N&&S[i]==S[i+2]){
      cout << i+1 << ' ' << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
  
}