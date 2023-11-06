#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool solve(vector<int> A){
  int axor = 0;
  for(auto &a:A) axor ^= a; 
  if(axor==0) return false;
  for(int i=0;i<A.size();i++){
    vector<int> nex;
    for(int j=0;j<A.size();j++){
      if(i!=j)nex.push_back(A[j]);
    }
    bool ret = solve(nex);
    if(ret==false) return true;
  }
  return false;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  cout << (solve(A)?"Yes":"No") << endl;
}