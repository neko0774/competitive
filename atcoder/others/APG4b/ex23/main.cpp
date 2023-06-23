#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  unordered_map<int, int> count;
  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
    count[A[i]]++;
  }
  pair<int, int> ans(-1, 0);
  for(int x:A){
    if(ans.second<count[x]){
      ans.first = x;
      ans.second = count[x];
    }
  }
  cout << ans.first << " " << ans.second << endl;
}