#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

void calc(vector<vector<int>> A, vector<int> &ANS, int x){
  ANS[x]++;
  if(A[x].size()==0){return;}
  for(int nx: A[x]){
    calc(A, ANS, nx);
    ANS[x] += ANS[nx];
  }
}

int main(){
  int N;
  cin >> N;
  vector<vector<int>> A(N);
  for(int i=0;i<N-1;i++){
    int tmp;
    cin >> tmp;
    A[tmp].push_back(i+1);
  }
  vector<int> ANS(N);
  calc(A, ANS, 0);
  for(int i=0;i<N;i++){
    cout << ANS[i] << endl;
  }
}