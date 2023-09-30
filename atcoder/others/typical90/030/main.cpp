#include<bits/stdc++.h>
using namespace std;
#define ll long long




int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> table(N+1, 0);
  for(int i=2;i<N+1;i++){
    if(table[i]==0){
      for(int j=i;j<N+1;j+=i){
        table[j]++;
      }
    }
  }
  ll ans = 0;
  for(auto a: table) if(a>=K) ans++;
  cout << ans << endl;
}