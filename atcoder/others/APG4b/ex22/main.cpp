#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<pair<int, int>> V(N);
  for(int i=0;i<N;i++){
    cin >> V[i].second  >> V[i].first;
  }
  sort(V.begin(), V.end());
  for(int i=0;i<N;i++){
    cout << V[i].second << " " << V[i].first << endl;
  }
} 