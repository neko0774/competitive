#include<bits/stdc++.h>
using namespace std;
short H,W,A[300][300];
int S[301][301];
int sum(int a, int b, int c, int d)
{
  return S[c][d]-S[a][d]-S[c][b]+S[a][b];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>H>>W;
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)
  {
    cin>>A[i][j];
    S[i+1][j+1]=A[i][j];
  }
  for(int i=0;i<H;i++)for(int j=0;j<=W;j++)S[i+1][j]+=S[i][j];
  for(int j=0;j<W;j++)for(int i=0;i<=H;i++)S[i][j+1]+=S[i][j];
  int ans=0;
  for(int r=0;r<H;r++)for(int c=0;c<W;c++)
  {
    for(int h=0;h<=10&&r+h<=H;h++)for(int w=0;w<=10&&c+w<=W;w++)
    {
      if(h*w>10)continue;
      ans+=(sum(r,c,r+h,c+w)==10);
    }
  }
  cout<<ans<<"\n";
}