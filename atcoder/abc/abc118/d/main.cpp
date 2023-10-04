#include <bits/stdc++.h>
using namespace std;

bool compare(string A, string B){

}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0;i<M;i++){
    cin >> A[i];
  }
  vector<int> conv = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<pair<int, int>> use;
  for(auto a:A){use.push_back(make_pair(a, conv[a-1]));}
  vector<unordered_map<int, int>> dp(N+1);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int nxt = min(i+use[j].first, N);
      
    }
  }
}