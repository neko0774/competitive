#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int N){
  if(N==1){
    cout << 1 << ' ';
    return;
  }
  solve(N-1);
  cout << N << ' ';
  solve(N-1);
  return;
}

int main(){
  int N;
  cin >> N;
  solve(N);
}