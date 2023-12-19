#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> V(N);
  for(int i=0;i<N;i++){
    cin >> V[i];
  }
  sort(V.rbegin(), V.rend());
  long double value = 0;
  int cnt = 0;
  for(int i=0;i<A;i++){
    value += V[i];
    if(V[i]==V[A-1])cnt++;
  }
  value /= A;

  int total = cnt;
  for(int i=A;i<N;i++){
    if(V[i]==V[A-1])total++;
  }

  //total choose cnt
}