#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_prime(int x){
  int i = 2;
  while(i*i<=x){
    if(x%i==0) return false;
    i++;
  }
  return true;
}


int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  for(int i=A;i<B+1;i++){
    bool impossible = true;
    for(int j=C;j<D+1;j++){
      if(is_prime(i+j)) impossible = false;
    }
    if(impossible){
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki" << endl;
}