#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N, W;
  cin >> N >> W;
  vector<pair<long long, int>> ch(N, pair<long long, int>());
  int A, B;
  for(int i=0;i<N;i++){
    cin >> A >> B;
    ch[i] = make_pair(A, B);
  }
  sort(ch.rbegin(), ch.rend());
  long long ans = 0;
  for(auto [A, B]: ch){
    if(B<=W){
      ans += A*B;
      W -= B;
    }else{
      ans += A*W;
      W = 0;
    }
  }
  cout << ans << endl;
}