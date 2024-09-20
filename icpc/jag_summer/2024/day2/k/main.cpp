#include<bits/stdc++.h>
using namespace std;
int ceil(int a, int b){return (a+b-1)/b;}
int solve(int L, int R, int K)
{
  int B=int(sqrtl(double(L)));
  for(int x=1;x<=B;x++)
  {
    if(x*ceil(L,x)>R)K--;
    if(K==0)return x;
  }
  int x=B+1;
  auto check=[&](int y)->bool
  {
    return y*ceil(L,y)<=R;
  };
  for(;x<L;x++)
  {
    int a=L/x,b=L%x;
    int n=b/a;
    if(b%a==0&&check(x+n))
    {
      int cnt=min(x+n,R/(a+1))-x+1;
      if(cnt<0)cnt=0;
      if(cnt+K<=n)return x+cnt+K;
      K-=n-cnt;
      x+=n;
      continue;
    }
    int cnt=min(x+n,R/(a+1))-x+1;
    if(cnt<0)cnt=0;
    if(cnt+K<=n+1)return x+cnt+K;
    K-=n+1-cnt;
    x+=n;
  }
  return R+K-1;
}

int naive(int L, int R, int K)
{
  for(int x=1;;x++)
  {
    if(x*ceil(L,x)>R)K--;
    if(K==0)return x;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  random_device seed;
  mt19937 eng(seed());
  while(1)
  {
    int L=eng()%10+1;
    int R=eng()%10+L;
    int K=eng()%10+1;
    int ac=naive(L,R,K);
    int wa=solve(L,R,K);
    if(ac==wa)
    {
      cout<<"AC : "<<L<<" "<<R<<" "<<K<<endl;
      continue;
    }
    cout<<"WA : "<<L<<" "<<R<<" "<<K<<endl;
    cout<<ac<<" "<<wa<<endl;
    return 0;
  }
  int Q;
  cin>>Q;
  while(Q--)
  {
    int L,R,K;
    cin>>L>>R>>K;
    cout<<solve(L,R,K)<<"\n";
  }
}