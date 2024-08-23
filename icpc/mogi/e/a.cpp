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
ll f(ll M, vector<ll> A)
{
  ll ans=0;
  ll rem=M;
  for(int i=0;i<A.size();i++)
  {
    if(A[i]>rem)
    {
      rem=M-A[i];
      ans++;
    }
    else rem-=A[i];
  }
  ans+=(rem<M);
  return ans;
}
bool solve()
{
  ll N,M;
  cin>>N>>M;
  if(N==0&&M==0)return false;
  vector<ll>A(N);
  for(ll i=0;i<N;i++)cin>>A[i];
  ll ans=f(M,A);
  for(int j=0;j<N-1;j++)
  {
    swap(A[j],A[j+1]);
    ans=min(ans,f(M,A));
    swap(A[j],A[j+1]);
  }
  cout<<ans<<endl;
  return true;
}
int main()
{
  while(solve()){}
}