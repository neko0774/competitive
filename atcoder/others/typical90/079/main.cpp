#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W, 0));
  vector<vector<ll>> B(H, vector<ll>(W, 0));
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      cin >> A[y][x];
    }
  }
  ll ans = 0;
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      cin >> B[y][x];
    }
  }
  for(int y=0;y<H-1;y++){
    for(int x=0;x<W-1;x++){
      if(A[y][x]!=B[y][x]){
        ll dif = -A[y][x]+B[y][x];
        ans += abs(A[y][x]-B[y][x]);
        for(int i=0;i<2;i++){
          for(int j=0;j<2;j++){
            A[y+i][x+j] += dif;
          }
        }
      }
    }
  }
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      if(A[y][x]!=B[y][x]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
}