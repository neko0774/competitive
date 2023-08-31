#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  vector<map<ll, ll>> cnt(H, map<ll, ll>());
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      cin >> A[y][x];
      cnt[y][A[y][x]]++;
    }
  }
  

}