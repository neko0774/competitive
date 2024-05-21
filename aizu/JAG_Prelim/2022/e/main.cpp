#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
bool solve()
{
  for(ll M=10;M<=20;M++)for(ll A=1;A<M;A++)
  {
    ll ans=0;
    ll g=gcd(A,M);
    for(ll x=1;x<M;x++)
    {
      if(gcd(M,x)==1&&(A*x)%M==A)ans++;
    }
    cout<<"(M,A,ans)=("<<M<<","<<A<<","<<ans<<")"<<endl;
  }
  return 0;
}
int main(){
  while(solve()){}
}