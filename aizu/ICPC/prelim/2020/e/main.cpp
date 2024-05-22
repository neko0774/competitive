#include<bits/stdc++.h>
using namespace std;

int main(){
  long long F1=1,F2=1;
  for(int i=3;i<=30;i++){
    long long F=F1+F2;
    F1=F2;
    F2=F;
  }
  cout<<F2<<endl;
  cout<<int(1e6)<<endl;
}