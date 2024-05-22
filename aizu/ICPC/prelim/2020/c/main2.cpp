#include<iostream>
#include<unordered_map>
using namespace std;
long long X,ans;
int P=0,N;
long long prime[1<<17];
pair<long long, long long>fac[1<<17];
void dfs(int p, long long a, long long b, long long c)
{
  if(p==N){
    ans=min(ans,a+b+c);
    return;
  }
  int n=fac[p].second;
  for(int i=0;i<=n;i++)for(int j=0;i+j<n;j++)
  {
    long long k=n-i-j;
    // if(k<0)continue;
    long long aa=a,bb=b,cc=c;
    for(int ii=0;ii<i;ii++)aa*=fac[p].first;
    for(int jj=0;jj<j;jj++)bb*=fac[p].first;
    for(int kk=0;kk<k;kk++)cc*=fac[p].first;
    dfs(p+1,aa,bb,cc);
  }
}
bool solve()
{
  long long X;
  cin>>X;
  if(X==0)return 0;
  ans=1LL<<60;
  N=0;
  for(int i=0;i<P;i++)
  {
    int p=prime[i];
    if(X%p==0){
      fac[N].first=p;
      while(X%p==0){
        fac[N].second++;
        X/=p;
      }
      N++;
    }
  }
  dfs(0,1LL,1LL,1LL);
  cout<<ans<<"\n";
  return 1;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int M=100;
  bool ett[M];
  for(int p=2;p<M;p++)ett[p]=1;
  for(int p=2;p<M;p++)if(ett[p]){
    prime[P++]=p;
    for(int j=p;j<M;j+=p)ett[j]=0;
  }
  while(solve()){}
}