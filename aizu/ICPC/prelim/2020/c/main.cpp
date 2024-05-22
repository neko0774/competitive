#include<iostream>
using namespace std;
long long X;
long long P[1<<17];
bool solve()
{
  cin>>X;
  if(X==0)return 0;
  long long ans=1LL<<60;
  int p=0;
  for(long long b=1;b*b<=X;b++)if(X%b==0){
    P[p++]=b;
    long long ac=X/b;
    for(int i=p;i--;){
      long long a=P[i];
      long long c=ac/a;
      if(ac%a==0){
        if(a+b+c<ans)ans=a+b+c;
        break;
      }
    }
  }
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}