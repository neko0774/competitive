#include <bits/stdc++.h>
using namespace std;


bool check(int y, int x, vector<vector<string>> &grid){
  for(int i=y;i<y+9;i++){
    for(int j=x;j<x+9;j++){
      if(!grid[i][j]==".") return false;
    }
  }
  for(int i=y;i<y+9;i++){
    for(int j=x;j<x+9;j++){
      if(!grid[i][j]=='.') return false;
    }
  }

}

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<string>> grid;
  for(int j=0;j<N;j++){
    vector<string> tmp;
    for(int i=0;i<M;i++){
      string s;
      cin >> s;
      tmp.push_back(s);
    }
    grid.push_back(tmp);
  }
  for(int j=0;j<N-8;j++){
    for(int i=0;i<M-8;i++){
      if(check(i, j, grid))cout << j+1 << ' ' << i+1 << endl;
    }
  }
}