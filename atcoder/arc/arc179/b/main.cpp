#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;

int main(){
  int M, N;
  cin >> M >> N;
  vector<int> X(M);
  for(int i=0;i<M;i++){
    cin >> X[i];
    X[i]--;
  }
  vector<vector<int>> G(M, vector<int>());
  for(int i=0;i<M;i++){
    G[i].push_back(X[i]);
  }

  

}