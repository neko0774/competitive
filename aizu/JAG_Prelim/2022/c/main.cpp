#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int N,pre[1010],suf[1010];
string S[1010];
void calc(int p, bool is_suf=0)
{
  int cnt=0;
  for(int i=0;i<N;i++)if(i!=p)
  {
    if(S[i].size()!=S[p].size())continue;
    for(int j=0;j<S[i].size()&&S[i][j]==S[p][j];j++)cnt=max(cnt,j+1);
  }
  (is_suf?suf[p]:pre[p])=cnt;
}
bool solve()
{
  cin>>N;
  if(N==0)return 0;
  for(int i=0;i<N;i++)cin>>S[i];
  for(int i=0;i<N;i++)calc(i);
  for(int i=0;i<N;i++)reverse(S[i].begin(),S[i].end());
  for(int i=0;i<N;i++)calc(i,1);
  int ans=0;
  for(int i=0;i<N;i++)
  {
    ans+=max<int>(0,S[i].size()-min(pre[i],suf[i])-2);
    reverse(S[i].begin(),S[i].end());
    // cout<<S[i]<<" "<<pre[i]<<" "<<suf[i]<<" ";
    // cout<<S[i].size()-min(pre[i]+1,suf[i]+1)<<endl;
  }
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}