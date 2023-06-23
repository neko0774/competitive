#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, S;
  cin >> N >> S;
  int ans = 0;
  unordered_map<int, int> A;
  unordered_map<int, int> P;
  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    A[tmp] += 1;
  }
  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    ans += A[S-tmp];
  }
  cout << ans << endl;

}