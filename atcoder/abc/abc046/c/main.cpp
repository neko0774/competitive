#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  ll T, A;
  cin >> T >> A;
  ll t, a;
  for(int i=0;i<N-1;i++){
    cin >> t >> a;
    ll v = max((T+t-1)/t, (A+a-1)/a);
    T =t*v;
    A =a*v;
    //T<=v*t and A<=v*a
    //T//t
  }  
  cout << T+A << endl;
}