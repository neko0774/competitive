#include<bits/stdc++.h>
using namespace std;
struct segtree
{
  int n,log,sz;
  vector<int>d;
  void update(int p){d[p]=max(d[2*p],d[2*p+1]);}
  segtree(int m):n(m)
  {
    log=1;
    while((1<<log)<n)log++;
    sz=1<<log;
    d.assign(2*sz,0);
  }
  void set(int p, int x)
  {
    p+=sz;
    d[p]=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  int prod(int l, int r)
  {
    l+=sz,r+=sz;
    int res=0;
    while(l<r)
    {
      if(l&1)res=max(res,d[l++]);
      if(r&1)res=max(res,d[--r]);
      l/=2,r/=2;
    }
    return res;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H,W,K;
  cin>>H>>W>>K;
  vector<vector<int>>TR(H);
  for(int i=0;i<K;i++)
  {
    int r,c;
    cin>>r>>c;
    r--,c--;
    TR[r].push_back(c);
  }
  segtree seg(W);
  for(int i=0;i<H;i++)
  {
    sort(TR[i].begin(),TR[i].end());
    for(int j:TR[i])
    {
      int cur=seg.prod(j+1,W);
      seg.set(j,cur+1);
    }
  }
  cout<<seg.prod(0,W)<<endl;
}