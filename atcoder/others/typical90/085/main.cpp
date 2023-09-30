#include<bits/stdc++.h>
using namespace std;
#define ll long long

void show(vector<ll> A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}

vector<ll> factorization(ll x){
  ll i = 1;
  vector<ll> one, two;
  while(i*i<=x){
    if (x%i==0){
      one.push_back(i);
      if(x/i!=i) two.push_back(x/i);
    }
    i++;
  }
  reverse(two.begin(), two.end());
  for(auto a: two) one.push_back(a); 
  return one;
}


int main(){
  ll K;
  cin >> K;
  vector<ll> fact = factorization(K);
  ll N = fact.size();
  ll ans = 0;
  //show(fact);
  for(auto a: fact){
    vector<ll> t = factorization(K/a);
    //cout << a << '|';
    //show(t);
    auto l = lower_bound(t.begin(), t.end(), a)-t.begin();
    ans += max(0ll, (ll)(t.size()+1)/2-l);
  }
  cout << ans << endl;
}