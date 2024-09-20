#include<bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>

int main(){
  int N, M;
  cin >> N >> M;
  atcoder::dsu uf(N + M * 2);
  vector<unordered_set<int>> grp(N);
  for(int i = 0; i < N; i++){
    int q;
    cin >> q;
    if(q == 0){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
    }else if(q == 1){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
    }else if(q == 2){
      int x;
      cin >> x;
      x--;
    }else{
      int x, y;
      cin >> x >> y;
      x--;
      y--;
    }
  }
}