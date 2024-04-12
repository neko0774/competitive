#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M));
  vector<ll> series;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> A[i][j];
      series.push_back(A[i][j]);
    }
  }

  sort(series.begin(), series.end());
  
}