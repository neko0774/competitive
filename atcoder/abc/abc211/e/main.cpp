#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> grid;

int main(){
  int N, K;
  cin >> N >> K;
  grid.resize(N, vector<int>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> grid[i][j];
    }
  }


}