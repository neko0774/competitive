#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;cin >> N;
  vector<int> C(9);
  int minv = N+1;
  int v = 0;
  for(int i=0;i<9;i++){
    cin >> C[i];
    if(C[i]<=minv){
      minv = C[i];
      v = i+1;
    }
  }
  int digits = N/minv;
  int left = N-minv*digits;
  string ans="";
  for(int j=0;j<digits;j++){
    for(int i=8;i>=0;i--){
      if(left>=C[i]-minv){
        ans += to_string(i+1);
        left -= C[i]-minv;
        break;
      }
    }
  }
  cout << ans << endl;
}