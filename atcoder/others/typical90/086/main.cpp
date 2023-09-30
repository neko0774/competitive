#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int main(){
  int N, Q;
  cin >> N >> Q;
  ll x, y, z, w;
  vector<vector<int>> A(N, vector<int>(60, 0));
  vector<vector<ll>> query;
  for(int i=0;i<Q;i++){
    cin >> x >> y >> z >> w;
    query.push_back({x, y, z, w});
  }
  

}