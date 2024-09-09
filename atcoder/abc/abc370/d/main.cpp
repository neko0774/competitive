#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int H, W, Q;
  cin >> H >> W >> Q;
  vector<set<int>> R(H), C(W);
  for(int w = 0; w < W; w++){
    for(int h = 0; h < H; h++){
      R[h].insert(w);
      C[w].insert(h);
    }
  }
  int r, c;
  for(int i = 0; i < Q; i++){
    cin >> r >> c;
    if(R[])
  }
}