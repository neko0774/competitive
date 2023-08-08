#include <bits/stdc++.h>
using namespace std;

void solve(){
  int N;
  cin >> N;
  vector<int> A(N);
  map<int> count;
  for(int i=0;i<N*(N-1)/2;i++){
    cin >> A[i];
    count.insert(A[i]);
  }
  int NN = N-count.size();
  for(auto nx: count) cout << nx << ' ';
  for(int i=0;i<NN;i++){

  }

}


int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}