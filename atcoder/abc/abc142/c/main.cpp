#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> A(N, pair<int, int>());
  int tmp;
  for(int i=0;i<N;i++){
    cin >> tmp;
    A[i] = make_pair(tmp, i);
  }
  sort(A.begin(), A.end());
  for(int i=0;i<N;i++){
    cout << A[i].second + 1 << ' ';
  }

}