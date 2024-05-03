#include<bits/stdc++.h>
using namespace std;
bool solve()
{
  int H,W;
  cin>>H>>W;
  if(H==0&&W==0)return 0;
  map<char,pair<int,int>>mp;
  for(int i=0;i<H;i++)
  {
    string r;
    cin>>r;
    for(int j=0;j<W;j++)mp[r[j]]=make_pair(i,j);
  }
  string S;
  cin>>S;
  long long ans=0;
  int r=0,c=0;
  for(char s:S)
  {
    auto[x,y]=mp[s];
    ans+=abs(r-x)+abs(y-c);
    ans++;
    r=x,c=y;
  }
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}