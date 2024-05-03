#include<bits/stdc++.h>
using namespace std;
int N,M,A[1010],B[1010],H[1010];
bool addL[1010],addR[1010];
int ans(int L, int R)
{
  if(L+1==R)return H[L];
  int m=*min_element(H+L,H+R);
  for(int i=L;i<R;i++)H[i]-=m;
  int res=m;
  int l=L,r=L;
  while(l<R)
  {
    while(r<R&&H[r]>0)r++;
    if(r>l)res+=ans(l,r);
    r++;
    l=r;
  }
  return res;
}
bool solve()
{
  cin>>N>>M;
  if(N==0&&M==0)return 0;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)cin>>B[i];
  for(int i=0;i<N;i++)
  {
    H[i]=(B[i]-A[i]+M)%M;
    addL[i]=addR[i]=false;
  }
  for(int i=1;i<N;i++)
  {
    if(H[i-1]+addL[i-1]*M>H[i]+(M+1)/2)addL[i]=1;
  }
  for(int i=N-2;i>=0;i--)
  {
    if(H[i+1]+addR[i+1]*M>H[i]+(M+1)/2)addR[i]=1;
  }
  for(int i=0;i<N;i++)if(addL[i]&&addR[i])H[i]+=M;
  cout<<ans(0,N)<<endl;
  return 1;
}
int main(){
  while(solve()){}
}