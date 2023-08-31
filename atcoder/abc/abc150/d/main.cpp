#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
  int N, M;
  cin >> M >> M;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll g=1;
  for(auto a: A) g = gcd(g, a);
  ll l = 1;
  for(auto a: A) a/= g;
}