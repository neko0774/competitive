#include<bits/stdc++.h>
using namespace std;
int N,M,P;
bool out[111];
bool solve(){
  cin>>N>>M>>P;
  if(N==0&&M==0&&P==0)return 0;
  for(int i=1;i<=N;i++)out[i]=0;
  out[P]=1;
  for(;M--;)
  {
    int u,v;
    cin>>u>>v;
    if(out[u])out[v]=1;
    if(out[v])out[u]=1;
  }
  int ans=0;
  for(int i=1;i<=N;i++)ans+=out[i];
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}