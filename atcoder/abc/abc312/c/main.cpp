#include <bits/stdc++.h>
using namespace std;



int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<M;i++){
    cin >> B[i];
  }
  sort(B.begin(), B.end());
  sort(A.begin(), A.end());

  int ok = 0;
  int bad = 1e9+1;
  while(abs(ok-bad)>1){
    int m = (ok+bad)/2;
    int cnt_apple=0, cnt_buyer=0;
    for(auto a: A){if(a>=m)cnt_apple++;}
    for(auto b: B){if(b<=m)cnt_buyer++;}
    //cout << ok << ' ' << bad << ' ' << m << ' ' << cnt_apple << ' ' << cnt_buyer << endl;
    if(cnt_apple>=cnt_buyer)ok = m;
    else bad = m;
  }
  cout << ok << endl;
}