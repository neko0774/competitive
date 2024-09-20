#include<bits/stdc++.h>
using namespace std;


int solve(int n, vector<pair<char, int>> hanoi, int turn){
  if(n == -1) return 0;
  int count = 0;
  if(hanoi[n].first == 'G'){
    
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<pair<char, int>> hanoi(N);
  for(int i = 0; i < N; i++){
    cin >> hanoi[i].first >> hanoi[i].second;
  }
}