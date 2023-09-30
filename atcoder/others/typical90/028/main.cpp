#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<vector<ll>> field(1010, vector<ll>(1010, 0));
  vector<ll> ans(N+1, 0);
  for(int i=0;i<N;i++){
    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    field[ay][ax]++;
    field[ay][bx]--;
    field[by][ax]--;
    field[by][bx]++;
  }
  for(int y=0;y<1005;y++){
    for(int x=1;x<1005;x++){
      field[y][x]+=field[y][x-1];
    }
  }
  for(int x=0;x<1005;x++){
    for(int y=1;y<1005;y++){
      field[y][x]+=field[y-1][x];
    }
  }
  for(int x=0;x<1000;x++){
    for(int y=0;y<1000;y++){
      ans[field[y][x]]++;
    }
  }
  for(int k=1;k<=N;k++){
    cout << ans[k] << endl;
  }
}