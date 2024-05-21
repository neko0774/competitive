#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int N;
string S[1010];
int calc(int p)
{
  int L=S[p].size();
  vector<pair<int,int>>ord;
  for(int l=1;l<L;l++)for(int r=L-1;r>=l;r--)ord.emplace_back(l,r);
  sort(ord.begin(),ord.end(),[](const pair<int,int>a,const pair<int,int>b)
  {
    return a.second-a.first>b.second-b.first;
  });
  for(auto[l,r]:ord)
  {
    bool ok=true;
    for(int i=0;i<N;i++)if(i!=p)
    {
      if(S[i].size()!=S[p].size())continue;
      bool fn=false;
      for(int j=0;j<l;j++)if(S[i][j]!=S[p][j])fn=true;
      for(int j=r;j<L;j++)if(S[i][j]!=S[p][j])fn=true;
      if(!fn)
      {
        ok=false;
        break;
      }
    }
    if(ok)return r-l;
  }
  return 0;
}
bool solve()
{
  cin>>N;
  if(N==0)return 0;
  for(int i=0;i<N;i++)cin>>S[i];
  int ans=0;
  for(int i=0;i<N;i++)
  {
    int add=calc(i);
    // cout<<S[i]<<" "<<add<<endl;
    ans+=add;
  }
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}