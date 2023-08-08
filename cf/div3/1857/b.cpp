#include <bits/stdc++.h>
using namespace std;

void solve(){
  string X, X1;
  cin >> X;
  int N = X.size();
  for(int i=0;i<N;i++){
    if(X[i]>='5'){
      while(i+1<N&&X[i+1]=='9'){
        i++;
      }
      if (i+1<N){
        string X1=to_string(X[i+1]+'1'-'0');
       cout << 13 << endl;
      }else {string X1 = "10";
        cout << X1 << endl;
      }
      cout << X1 << endl;
      cout <<i+1 << ' ' << N << ' ' << X << endl;
      for(int j=0;j<i;j++){
        X1 += '0';
      }
      string X = X1;
    }
  }
  cout << X << endl;
}


int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}