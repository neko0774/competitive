#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> ans;
  if(N>0){
    ans.push_back(make_pair(2, 1e9));
    ans.push_back(make_pair(1, 3));
    for(int i=0;i<N-2;i++){
      ans.push_back(make_pair((i+2)*2, (i+2)*2+1));
    } 
  }
  else if(N<0){
    
  }
  else{
    for(int i=1;i<N;i++){
      ans.push_back(make_pair(i*2-1, i*2));
    }
  }

}