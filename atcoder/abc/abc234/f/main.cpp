#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;

void show(vector<ll> A){
  for(auto a:A) cout << a << ' ';
  cout << endl;
}

ll sum(vector<ll> A){
  ll ret = 0;
  for(auto &a: A){
    ret += a;
    ret %= mod;
  }
  return ret;
}

int main(){
  string S;
  cin >> S;
  int N = S.length();
  vector<ll> count(N, 0);
  for(auto &s:S) count[s-'a']++;

  
}