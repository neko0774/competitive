#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;
  unordered_map<int, vector<int>> ext;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    ext[a].push_back(i);
  }
  for(int i=0;i<Q;i++){
    int x, k;
    cin >> x >> k;
    if(ext[x].size()<k) cout << -1 << endl;
    else cout << ext[x][k-1]+1 << endl;
  }
}