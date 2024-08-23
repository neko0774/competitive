#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void change(pair<ll,ll>&p, pair<ll,ll>q)
{
  if(p.first>q.first)p=q;
  else if(p.first==q.first&&p.second<q.second)p=q;
}
pair<ll,ll>dp[2<<17][2];
const pair<ll,ll>init=make_pair(1LL<<60,0);
bool solve()
{
  ll N,M;
  cin>>N>>M;
  if(N==0&&M==0)return false;
  vector<ll>A(N);
  for(ll i=0;i<N;i++)cin>>A[i];
  for(ll i=0;i<=N;i++)for(int j=0;j<2;j++)dp[i][j]=init;
  dp[0][0]=make_pair(0,M);
  for(ll i=0;i<N;i++)
  {
    // swap
    {
      if(i+1<N)
      {
        auto[k,rem]=dp[i][0];
        if(A[i+1]<=rem&&rem-A[i+1]<A[i])
        {
          change(dp[i+2][1],make_pair(k+1,M-A[i]));
        }
        if(A[i+1]>rem&&A[i]+A[i+1]>M)
        {
          change(dp[i+2][1],make_pair(k+2,M-A[i]));
        }
      }
    }
    // not
    {
      for(int j=0;j<2;j++)
      {
        auto[k,rem]=dp[i][j];
        if(rem<A[i])
        {
          change(dp[i+1][j],make_pair(k+1,M-A[i]));
        }
        else
        {
          change(dp[i+1][j],make_pair(k,rem-A[i]));
        }
      }
    }
    // cout<<dp[i][0].first<<" "<<dp[i][0].second<<" "<<dp[i][1].first<<" "<<dp[i][1].second<<endl;
  }
  // cout<<dp[N][0].first<<" "<<dp[N][0].second<<" "<<dp[N][1].first<<" "<<dp[N][1].second<<endl;
  ll ans=1LL<<60;
  for(int j=0;j<2;j++)
  {
    auto[k,rem]=dp[N][j];
    ans=min(ans,k+(rem<M?1:0));
  }
  cout<<ans<<endl;
  return true;
}
int main()
{
  while(solve()){}
}