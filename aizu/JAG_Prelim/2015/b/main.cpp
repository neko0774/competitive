#include<bits/stdc++.h>
using namespace std;
string code(string S, int k)
{
  string t;
  t.push_back(S[0]);
  for(int i=1;i<S.size();i++)
  {
    if(t.size()==k)return t;
    if([&]
    {
      for(char c:"aeiou")if(S[i-1]==c)return 1;
      return 0;
    }())t.push_back(S[i]);
  }
  return t;
}
bool solve()
{
  int N;
  cin>>N;
  if(N==0)return 0;
  vector<string>names(N);
  for(int i=0;i<N;i++)cin>>names[i];
  int ans=100;
  for(int k=1;k<=50;k++)
  {
    set<string>codes;
    bool ok=1;
    for(string s:names)
    {
      string t=code(s,k);
      if(codes.count(t))
      {
        ok=0;
        break;
      }
      codes.insert(t);
    }
    if(ok)
    {
      ans=k;
      break;
    }
  }
  if(ans==100)ans=-1;
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}