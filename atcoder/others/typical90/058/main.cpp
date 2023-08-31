#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(ll x){
  ll y=0;
  ll xx=x;
  while(x){
    y += x%10;
    x /= 10;
  }
  return (xx+y)%100000;
}

ll cnt(ll x){
  ll ret = 0;
  while(x){
    ret++;
    x/=2;
  }
  return ret;
}

int main(){
  ll N, K;
  cin >> N >> K;
  ll NN = 1e5;
  vector<vector<ll>> table(cnt(K+5)+1, vector<ll>(NN+1));
  for(int i=0;i<=NN;i++){
    table[0][i] = calc(i);
  }
  
  for(int i=1;i<cnt(K+5);i++){
    for(int j=0;j<NN+1;j++){
      table[i][j] = table[i-1][table[i-1][j]];
      //cout << table[i][j] << ' ';
    }
    //cout << endl;
  }
  int i = 0;
  while(K){
    //if(K&1) cout << 1;
    //else cout << 0;
    if(K&1){
      N = table[i][N];
    }
    i++;
    K/=2;
  }
  cout << N << endl;
}