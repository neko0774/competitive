#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N, M;
  cin >> N >> M;
  vector<unordered_set<int>> F(N);
  vector<int> P(N), C(N);
  int tmp;
  for(int i=0;i<N;i++){
    cin >> P[i] >> C[i];
    for(int j=0;j<C[i];j++){
      cin >> tmp;
      F[i].insert(tmp); 
    }
  }

  bool exist = false;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      bool low_price = false, functions = true, superior = false;
      if(P[i]>=P[j]) low_price=true;
      for(auto f:F[i]){
        if(F[j].count(f)==0) functions=false;
      }
      if(P[i]>P[j]||F[j].size()>F[i].size()) superior=true;
      if(low_price&&functions&&superior)exist=true;
    }
  }
  cout << (exist?"Yes":"No") << endl;
}