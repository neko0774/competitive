#include<bits/stdc++.h>
using namespace std;
int H,W;
int Hor[505][505],Ver[505][505];
bool vis[505][505][2];
bool solve()
{
  int R,C;
  cin>>H>>W>>R>>C;
  if(H==0&&W==0&&R==0&&C==0)return 0;
  for(int j=1;j<=W;j++)cin>>Hor[0][j];
  for(int i=1;i<=H;i++)
  {
    for(int j=0;j<=W;j++)cin>>Ver[i][j];
    for(int j=1;j<=W;j++)cin>>Hor[i][j];
  }
  for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)for(int f=0;f<2;f++)vis[i][j][f]=0;
  queue<tuple<int,int,int>>q;
  {
    if(Hor[0][1]^Ver[1][0])
    {
      vis[1][1][0]=vis[1][1][1]=1;
      q.push(make_tuple(1,1,0));
      q.push(make_tuple(1,1,1));
    }
    if(Hor[0][W]^Ver[1][W])
    {
      vis[1][W][0]=vis[1][W][1]=1;
      q.push(make_tuple(1,W,0));
      q.push(make_tuple(1,W,1));
    }
    if(Hor[H][1]^Ver[H][0])
    {
      vis[H][1][0]=vis[H][1][1]=1;
      q.push(make_tuple(H,1,0));
      q.push(make_tuple(H,1,1));
    }
    if(Hor[H][W]^Ver[H][W])
    {
      vis[H][W][0]=vis[H][W][1]=1;
      q.push(make_tuple(H,W,0));
      q.push(make_tuple(H,W,1));
    }
    if(H==1)
    {
      for(int j=1;j<=W;j++)if(Hor[0][j]^Hor[1][j])
      {
        vis[1][j][0]=vis[1][j][1]=1;
        q.push(make_tuple(1,j,0));
        q.push(make_tuple(1,j,1));
      }
    }
    if(W==1)
    {
      for(int i=1;i<=H;i++)if(Ver[i][0]^Ver[i][1])
      {
        vis[i][1][0]=vis[i][1][1];
        q.push(make_tuple(i,1,0));
        q.push(make_tuple(i,1,1));
      }
    }
  }
  while(!q.empty()){
    auto[r,c,f]=q.front();
    q.pop();
    if(r>1)
    {
      bool g=Hor[r-1][c];
      if(!vis[r-1][c][g])
      {
        vis[r-1][c][g]=1;
        q.push(make_tuple(r-1,c,g));
      }
    }
    if(c>1)
    {
      bool g=Ver[r][c-1];
      if(!vis[r][c-1][g])
      {
        vis[r][c-1][g]=1;
        q.push(make_tuple(r,c-1,g));
      }
    }
    if(r<H)
    {
      bool g=Hor[r][c];
      if(!vis[r+1][c][g])
      {
        vis[r+1][c][g]=1;
        q.push(make_tuple(r+1,c,g));
      }
    }
    if(c<W)
    {
      bool g=Ver[r][c];
      if(!vis[r][c+1][g])
      {
        vis[r][c+1][g]=1;
        q.push(make_tuple(r,c+1,g));
      }
    }
  }
  if(R==1&&!Hor[0][C])vis[R][C][0]=1;
  if(R==H&&!Hor[H][C])vis[R][C][0]=1;
  if(C==1&&!Ver[R][0])vis[R][C][0]=1;
  if(C==W&&!Ver[R][W])vis[R][C][0]=1;
  cout<<(vis[R][C][0]?"Yes":"No")<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}