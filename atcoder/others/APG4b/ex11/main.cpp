#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A;
  cin >> N;
  cin >> A;
  bool isvalid = true;
  for (int i=0; i<N; i++){
    string op;
    int tmp;
    cin >> op >> tmp;
    if(op=="+"){A+=tmp;}
    else if(op=="-"){A-=tmp;}
    else if(op=="*"){A*=tmp;}
    else if(op=="/"&&tmp!=0){A/=tmp;}
    else{
      if(isvalid){cout << "error" << endl;}
      isvalid=false;
    }
    if (isvalid){
      cout << i+1 << ":" << A << endl;
    }
  }
  
}