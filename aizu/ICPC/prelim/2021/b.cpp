#include<bits/stdc++.h>
using namespace std;

bool solve()
{
  int H,W;
  cin>>H>>W;
  if(H==0&&W==0)return 0;
  vector<vector<int>>A(H+1,vector<int>(W+1));
  for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)
  {
    char c;
    cin>>c;
    A[i][j]=c-'0';
  }
  double lh=0,rh=H;
  while(rh-lh>1e-8)
  {
    double mh=(rh+lh)/2;
    double sum=0;
    for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)sum+=A[i][j]*(i-mh);
    if(sum<=0)rh=mh;
    else lh=mh;
  }
  double lw=0,rw=W;
  while(rw-lw>1e-8)
  {
    double mw=(rw+lw)/2;
    double sum=0;
    for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)sum+=A[i][j]*(j-mw);
    if(sum<=0)rw=mw;
    else lw=mw;
  }
  cout<<fixed<<setprecision(16)<<rh<<' '<<rw<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}