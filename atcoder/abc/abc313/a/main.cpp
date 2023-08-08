#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  unordered_map<int, int> count;
  int v = 0;
  for(int i=0;i<N;i++){
    cin >> P[i];
    count[P[i]]++;
    v = max(v, P[i]);
  }
  if(P[0]==v&&count[v]==1) cout << 0 << endl;
  else cout << v-P[0]+1 << endl;
}