#include<bits/stdc++.h>
using namespace std;
int id[500][500],cnt[500*500];
int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};
bool vis[500][500];
int solve(int H, int W, vector<string>S){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)
  {
    id[i][j]=0;
    cnt[i*W+j]=0;
    vis[i][j]=false;
  }
  int num=0;
  int sr=-1,sc=-1;
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(!vis[i][j]&&S[i][j]!='#')
  {
    vis[i][j]=1;
    num++;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(q.size())
    {
      auto[r,c]=q.front();
      q.pop();
      id[r][c]=num;
      cnt[num]++;
      if(S[r][c]=='S')
      {
        sr=r,sc=c;
      }
      for(int d=0;d<4;d++)
      {
        int tr=r+dr[d];
        int tc=c+dc[d];
        if(0<=tr&&tr<H&&0<=tc&&tc<W&&S[tr][tc]!='#'&&!vis[tr][tc])
        {
          vis[tr][tc]=1;
          q.push({tr,tc});
        }
      }
    }
  }
  assert(sr!=-1&&sc!=-1);
  int start=id[sr][sc];
  int ans=0;
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(id[i][j]==start)
  {
    for(int d=0;d<4;d++)
    {
      int tr=i+dr[d];
      int tc=j+dc[d];
      if(0<=tr&&tr<H&&0<=tc&&tc<W&&S[tr][tc]=='#')
      {
        ans=max(ans,1);
        set<int>nxt;
        for(int e=0;e<4;e++)
        {
          int ttr=tr+dr[e];
          int ttc=tc+dc[e];
          if(0<=ttr&&ttr<H&&0<=ttc&&ttc<W&&id[ttr][ttc]>0&&id[ttr][ttc]!=id[i][j])
          {
            nxt.insert(id[ttr][ttc]);
          }
        }
        int sum=0;
        for(int j:nxt)sum+=cnt[j];
        ans=max(ans,sum+1);
      }
    }
  }
  ans+=cnt[start];
  // cout<<ans<<endl;
  return ans;
}

int bfs(vector<string>S)
{
  int H=S.size(),W=S[0].size();
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(S[i][j]=='S')
  {
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<vector<bool>>vis(H,vector<bool>(W,false));
    vis[i][j]=1;
    int ans=0;
    while(q.size())
    {
      auto[r,c]=q.front();
      q.pop();
      ans++;
      for(int d=0;d<4;d++)
      {
        int tr=r+dr[d];
        int tc=c+dc[d];
        if(0<=tr&&tr<H&&0<=tc&&tc<W&&!vis[tr][tc]&&S[tr][tc]!='#')
        {
          vis[tr][tc]=1;
          q.push({tr,tc});
        }
      }
    }
    return ans;
  }
  return 0;
}

int naive(int H, int W, vector<string>S)
{
  int ans=bfs(S);
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)
  {
    if(S[i][j]=='#')
    {
      S[i][j]='.';
      ans=max(ans,bfs(S));
      // for(string s:S)cout<<s<<endl;
      // cout<<solve(S)<<endl;
      S[i][j]='#';
    }
  }
  return ans;
}

int main()
{
  random_device seed;
  mt19937 eng(seed());
  while(0)
  {
    int H=eng()%60+2;
    int W=eng()%60+2;
    vector<string>S(H,string(W,'.'));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(eng()%3==0)S[i][j]='#';
    S[eng()%H][eng()%W]='S';
    int ac=naive(H,W,S);
    int wa=solve(H,W,S);
    if(ac==wa)
    {
      cout<<"AC : ";
      cout<<H<<" "<<W<<endl;
      continue;
    }
    cout<<"AC : ";
    cout<<H<<" "<<W<<endl;
    for(string s:S)cout<<s<<endl;
    cout<<ac<<" "<<wa<<endl;
    return 0;
  }
  int H,W;
  cin>>H>>W;
  vector<string>S(H);
  for(int i=0;i<H;i++)cin>>S[i];
  cout<<solve(H,W,S)<<endl;
}