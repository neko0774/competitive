#include<bits/stdc++.h>
using namespace std;


int main(){
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  set<int> S;
  int v = N+1;
  for(int i=0;i<K;i++){
    S.insert(P[i]);
    v = min(v, P[i]);
  }
  cout << v << endl;
  for(int i=K;i<N;i++){
    if(P[i]>v){
      S.insert(P[i]);
      v = *S.upper_bound(v);
    }
    cout << v << endl;
  }

}