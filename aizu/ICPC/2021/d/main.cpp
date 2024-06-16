#include<bits/stdc++.h>
using namespace std;
void chmax(int &a, int b){if(a<b)a=b;}
pair<int,int> calc(int a, int b, int c)
{
  int d=min({a,b,c});
  a-=d,b-=d,c-=d;
  if(a==0)return make_pair(b,c);
  if(b==0)return make_pair(a,c);
  return make_pair(a,b);
}
bool solve(){
  int N;
  cin>>N;
  if(N==0)return 0;
  vector<int>B[3];
  for(int i=0;i<N;i++)
  {
    int b;
    cin>>b;
    B[b%3].push_back(b);
  }
  for(int i=0;i<3;i++)
  {
    sort(B[i].begin(),B[i].end());
    reverse(B[i].begin(),B[i].end());
  }
  int X=B[0].size(),Y=B[1].size(),Z=B[2].size();
  const int M=50;
  const int INF=1<<25;
  int dp[X+1][Y+1][Z+1][M+1][M+1];
  for(int i=0;i<=X;i++)for(int j=0;j<=Y;j++)for(int k=0;k<=Z;k++)
  {
    for(int a=0;a<=M;a++)for(int b=0;b<=M;b++)dp[i][j][k][a][b]=-INF;
  }
  dp[0][0][0][0][0]=0;
  for(int i=0;i<=X;i++)for(int j=0;j<=Y;j++)for(int k=0;k<=Z;k++)
  {
    for(int a=0;a<=M;a++)for(int b=0;b<=M;b++)
    {
      if(i<X)
      {
        int c=B[0][i];
        int d=min({a,b,c});
        auto[p,q]=calc(a,b,c);
        chmax(dp[i+1][j][k][p][q],dp[i][j][k][a][b]+d);
      }
      if(j<Y)
      {
        int c=B[1][j];
        int d=min({a,b,c});
        auto[p,q]=calc(a,b,c);
        chmax(dp[i][j+1][k][p][q],dp[i][j][k][a][b]+d);
      }
      if(k<Z)
      {
        int c=B[2][k];
        int d=min({a,b,c});
        auto[p,q]=calc(a,b,c);
        chmax(dp[i][j][k+1][p][q],dp[i][j][k][a][b]+d);
      }
    }
  }
  int ans=0;
  for(int a=0;a<=M;a++)for(int b=0;b<=M;b++)chmax(ans,dp[X][Y][Z][a][b]);
  cout<<ans<<"\n";
  return 1; 
}


int main(){
  while(solve()){}
}