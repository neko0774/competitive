#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int A, B;
  cin >> A >> B;
  if (A == 0 && B == 0) return false;
  cout << A + B << endl;
  return true;
}

int main(){
  while(solve()){}
}