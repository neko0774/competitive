#include<bits/stdc++.h>
using namespace std;
int N,P[2<<17],A[2<<17];
vector<int>G[2<<17];
int sub[2<<17],X[2<<17];
void dfs(int u)
{
  for(int v:G[u])
  {
    dfs(v);
    sub[u]^=sub[v];
    X[u]^=sub[v];
  }
  X[u]^=A[u];
  sub[u]^=X[u];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>N;
  for(int i=1;i<N;i++)
  {
    cin>>P[i];
    P[i]--;
    G[P[i]].push_back(i);
  }
  for(int i=0;i<N;i++)cin>>A[i];
  dfs(0);
  int ans=0;
  for(int i=0;i<N;i++)ans+=X[i];
  int Q;
  cin>>Q;
  auto update=[&](int u)->void
  {
    ans-=X[u];
    X[u]^=1;
    ans+=X[u];
  };
  while(Q--)
  {
    int u;
    cin>>u;
    u--;
    update(u);
    if(u>0)update(P[u]);
    cout<<ans<<"\n";
  }
}