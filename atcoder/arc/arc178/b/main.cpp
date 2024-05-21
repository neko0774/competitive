#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;

void solve(){
  int A, B, C;
  cin >> A >> B >> C;
  if(A>B) swap(A, B);
  if(!(B==C||B+1==C)){
    cout << 0 << endl;
    return 0;
  }
  
}

int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}