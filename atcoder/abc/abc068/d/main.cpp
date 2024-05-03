#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  ll K;
  cin >> K;
  int N = 50;
  vector<ll> A(N, K/50);
  for(int i=0;i<K%50;i++){
    A[i] += 50;
  }
  cout << N << endl;
  for(int i=0;i<N;i++){
    cout << A[i] << ' ';
  }
}