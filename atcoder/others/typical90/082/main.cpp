#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#include<atcoder/all>
using mint = atcoder::modint1000000007;
const ll mod = 1e9+7;

ll count(ll c){
  mint ans = 0;
  ll p = 1;
  for(int i=0;i<19;i++){
    if(p*10>c){
      ans += (mint)(c-p+1)*(c+p)/2*(i+1);
      break;
    }
      ans += (mint)(p*10-p)*(p*10+p-1)/2*(i+1);
    p*=10;
  }
  return (ll)ans.val();
}

int main(){
  ll L, R;
  cin >> L >> R;
  cout << (count(R)-count(L-1)+mod)%mod << endl;
}