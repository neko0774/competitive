#include<bits/stdc++.h>
using namespace std;
#define ll long long





int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, ll>>> G(N, vector<pair<int, ll>>());
  ll c;
  int a, b;
  for(int i=0;i<M;i++){
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back(make_pair(b, c));
  }
}