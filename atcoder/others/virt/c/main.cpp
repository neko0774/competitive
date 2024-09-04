#include<bits/stdc++.h>
using namespace std;

int solve(){
  int M, N;
  cin >> M >> N;  
  if(M==0) return false;
  int MAX = 7368793;
  vector<int> table(MAX);
  for(int i=M, n = 0; n<N;i++){
    if(table[i]!=0) continue;
    n++;
    for(int j=i;j<MAX;j+=i){
      table[j] = i;
    }
  }
  for(int i=M;i<MAX;i++){
    if(table[i]==0){
      cout << i << endl;
      return true;
    }
  }
  return false;
}


int main(){
  while(solve()){}
}