#include <bits/stdc++.h>
using namespace std;



int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<long long> V(N);
  for(int i=0;i<N;i++){
    cin >> V[i];
  }
  unordered_map<long long, int> cnt;
  cnt[0]++;
  for(int i=0;i<N;i++){
    unordered_map<long long, int> nxt=cnt;
    for(auto x: cnt){
      nxt[x.first+V[i]]+=x.second;
    }
    cnt = nxt;
  }
  long long v = 0;
  
}