#include<iostream>
using namespace std;
#define ll long long
ll INF = 1e18;
ll gcd(ll A, ll B){
  if(B==0) return A;
  return gcd(B, A%B);
}
int main(){
  ll A, B;
  cin >> A >> B;
  ll g = B/gcd(A, B);
  if(g>INF/A) cout << "Large" << endl;
  else cout << A*g << endl;
}