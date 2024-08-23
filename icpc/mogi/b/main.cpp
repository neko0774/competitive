#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int N;
  cin>>N;
  if(N==0)return false;
  string ans="";
  int i=0;
  for(;N--;)
  {
    string S;
    char C;
    cin>>S>>C;
    if(S[0]=='I')
    {
      string T="";
      for(int j=0;j<ans.size();j++)
      {
        if(j==i)T.push_back(C);
        T.push_back(ans[j]);
      }
      if(i==ans.size())T.push_back(C);
      ans=T;
      i++;
    }
    else if(S[0]=='L')
    {
      if(i!=0)i--;
    }
    else
    {
      if(i!=ans.size())i++;
    }
  }
  cout<<ans<<endl;
  return true;
}

int main(){
  while(solve()){}
}