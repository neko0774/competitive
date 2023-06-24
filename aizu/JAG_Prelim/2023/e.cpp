#include<bits/stdc++.h>
using namespace std;
long long modpow(long long x, long long n, long long p) {
  if(n==0)return 1;
  long long res = modpow(x*x%p,n/2,p);
  if(n & 1)res = res * x % p;
  return res;
}

bool solve(){
  long long a,b;
  cin>>a >>b;
  if(a==0 && b==0)return 0;
  long long  g=gcd(a,b);
  a/=g; b/=g;
  if(a==1){
    cout << 0 << " " << 1 << endl;
    return 1;
  }
  long long p=modpow(b,a-2,a);
  if(2*p<=a){
    cout << p << " " << b*p/a << endl;
    return 1;
  }
  else{
    cout << a-p << " " << b-b*p/a << endl;
    return 1;
  }
}

int main() {
  while(solve()){}
}