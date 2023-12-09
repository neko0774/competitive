#include <bits/stdc++.h>
using namespace std;
#define ll long long

void show(vector<ll> A){
  for(auto a:A )cout << a  << ' ';
  cout << endl;
}

bool good(ll x, vector<ll> H, ll A, ll B){
  ll cnt = 0;
  ll d = A-B;
  for(auto &h:H){
    h-=x*B;
    if(h>0) cnt += (h+d-1)/d;
  }
  return cnt<=x;
}


int main(){
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> H(N);
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  ll ok = 1e9+1, ng = 0;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    if (good(mid, H, A, B)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}