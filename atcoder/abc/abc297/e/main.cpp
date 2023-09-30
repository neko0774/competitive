#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main(){
  int N;ll K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  set<ll> price;
  price.insert(0);
  for(int i=0;i<K;i++){
    ll p = INF;
    for(auto a: A){
      ll v = *price.rbegin()+1-a;
      ll vv = *price.lower_bound(v);
      p = min(p, vv+a);
    }
    price.insert(p);
  }
  cout << *price.rbegin() << endl;
}