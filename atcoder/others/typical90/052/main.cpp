#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

int main(){
  int N;
  ll ans = 1;
  cin >> N;
  for(int i=0;i<N;i++){
    ll cnt=0;
    for(int j=0;j<6;j++){
      ll A;
      cin >> A;
      cnt += A;
      cnt %= MOD;
    }
    ans *= cnt;
    ans %= MOD;
  }
  cout << ans << endl;
}