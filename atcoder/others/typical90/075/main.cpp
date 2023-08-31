#include<bits/stdc++.h>
using namespace std;
template<typename T>
#define ll long long

vector<pair<T, T>> factorization(T N){
  T i=2;
  vector<pair<T, T>> ret;
  while(i*i<=N){
    T cnt=0;
    while(N%i==0){
      cnt++;
      N/=i;
    }
    if(cnt>=1)ret.push_back(make_pair(i, cnt));
    i++;
  }
  if(N!=1)ret.push_back(make_pair(N, 1));
  return ret;
}

int main(){
  ll N;
  cin >> N;
  vector<pair<ll, ll>> num = factorization(N);
  ll cnt = 0;
  for(auto c: num) cnt += c.second;
  ll ans = 0;
  ll c=1;
  while(cnt>c){
    ans++;
    c*=2;
  } 
  cout << ans << endl;
}