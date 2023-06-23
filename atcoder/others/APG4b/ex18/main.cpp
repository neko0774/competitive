#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main(){
  int N, M;
  cin >> N >> M;
  int A, B;
  vector<vector<string>> ans(N, vector<string>(N, "-"));
  for(int i=0;i<M;i++){
    cin >> A >> B;
    A -=1;
    B -=1;
    ans[A][B] = "o";
    ans[B][A] = "x";
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
      cout << ans[i][j] << " ";
    }
    cout << ans[i][N-1];
    cout << endl;
  }
}