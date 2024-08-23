#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using mint=atcoder::modint998244353;
mint dp[55][1<<10];
bool solve(){
  int N,M,K;
  cin>>N>>M>>K;
  if(N==0&&M==0&&K==0)return false;
  vector<pair<int,int>>E(M);
  for(int i=0;i<M;i++)
  {
    int a,b;
    cin>>a>>b;
    a--,b--;
    E[i]=make_pair(a,b);
  }
  mint ans=0;
  const mint inv=mint(M).inv();
  for(int i=0;i<N;i++)
  {
    for(int k=0;k<=K;k++)for(int j=0;j<1<<N;j++)dp[k][j]=0;
    dp[0][1<<i]=1;
    for(int k=0;k<K;k++)
    {
      for(int j=0;j<1<<N;j++)
      {
        for(auto[a,b]:E)
        {
          if((j>>a&1)&&(j>>b&1))
          {
            dp[k+1][j]+=dp[k][j]*inv;
          }
          else if(j>>a&1)
          {
            dp[k+1][j^(1<<b)]+=dp[k][j]*inv;
          }
          else if(j>>b&1)
          {
            dp[k+1][j^(1<<a)]+=dp[k][j]*inv;
          }
          else
          {
            dp[k+1][j]+=dp[k][j]*inv;
          }
        }
      }
    }
    mint cur=0;
    for(int j=0;j<1<<N;j++)if(j&1)cur+=dp[K][j];
    ans+=cur;
  }
  cout<<ans.val()<<endl;
  return true;
}

int main(){
  while(solve()){}
}