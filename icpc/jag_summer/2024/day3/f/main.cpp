#include<bits/stdc++.h>
using namespace std;
int N,P[1<<17];
vector<int>solve()
{
  vector<long long>cnt(N,1);
  for(int i=0;i<N;i++)
  {
    for(int j=i+1;j<N;j++)if(P[i]>P[j])cnt[i]+=1LL<<(N-j-1);
  }
  long long rem=1LL<<(N-1);
  vector<int>ans;
  for(int i=0;i<N;i++)if(cnt[i]<=rem)
  {
    rem-=cnt[i];
    ans.push_back(P[i]);
  }
  return ans;
}
vector<int>naive()
{
  vector<vector<int>>all;
  for(int i=0;i<1<<N;i++)
  {
    vector<int>A;
    for(int j=0;j<N;j++)if(i>>j&1)A.push_back(P[j]);
    all.push_back(A);
  }
  sort(all.begin(),all.end());
  return all[1<<(N-1)];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  random_device seed;
  mt19937 eng(seed());
  while(1)
  {
    N=eng()%10+1;
    for(int i=0;i<N;i++)P[i]=i+1;
    shuffle(P,P+N,eng);
    auto ac=naive();
    auto wa=solve();
    if(ac==wa)
    {
      cout<<"AC : "<<N<<endl;
      continue;
    }
    cout<<"WA : "<<N<<endl;
    for(int i=0;i<N;i++)cout<<P[i]<<" ";cout<<endl;
    for(int a:ac)cout<<a<<" ";cout<<endl;
    for(int w:wa)cout<<w<<" ";cout<<endl;
    return 0;
  }
  cin>>N;
  for(int i=0;i<N;i++)cin>>P[i];
  auto ans=solve();
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<" \n"[i+1==ans.size()];
}