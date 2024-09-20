#include<bits/stdc++.h>
using namespace std;
template<typename S, auto op, auto e>
struct segtree
{
  int n,log,sz;
  vector<S>d;
  void update(int p){d[p]=op(d[2*p],d[2*p+1]);}
  segtree(int m):n(m)
  {
    log=1;
    while((1<<log)<n)log++;
    sz=1<<log;
    d.assign(2*sz,e());
  }
  S get(int p)
  {
    p+=sz;
    return d[p];
  }
  void set(int p, S x)
  {
    p+=sz;
    d[p]=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  void add(int p, S x)
  {
    p+=sz;
    d[p]+=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  S prod(int l, int r)
  {
    l+=sz,r+=sz;
    S pl=e(),pr=e();
    while(l<r)
    {
      if(l&1)pl=op(pl,d[l++]);
      if(r&1)pr=op(d[--r],pr);
      l/=2,r/=2;
    }
    return op(pl,pr);
  }
  S all_prod(){return d[1];}
};
long long op(long long a, long long b){return a+b;}
long long e(){return 0;}
void cmp(vector<int>&V)
{
  auto B=V;
  sort(B.begin(),B.end());
  B.erase(unique(B.begin(),B.end()),B.end());
  for(int &v:V)v=lower_bound(B.begin(),B.end(),v)-B.begin();
}
int N;
vector<int>Qs[1<<17];
long long solve(vector<int>P,vector<int>Q)
{
  cmp(P),cmp(Q);
  for(int i=0;i<N;i++)
  {
    Qs[P[i]].push_back(Q[i]);
  }
  segtree<long long,op,e>seg1(N),seg2(N),seg3(N);
  for(int p=0;p<N;p++)
  {
    sort(Qs[p].begin(),Qs[p].end());
    int K=Qs[p].size();
    vector<long long>cnt2(K),cnt3(K);
    for(int i=0;i<K;i++)
    {
      int q=Qs[p][i];
      cnt2[i]=seg1.prod(0,q);
      cnt3[i]=seg2.prod(0,q);
    }
    for(int i=0;i<K;i++)
    {
      int q=Qs[p][i];
      seg1.add(q,1);
      seg2.add(q,cnt2[i]);
      seg3.add(q,cnt3[i]);
    }
  }
  return seg3.all_prod();
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  random_device seed;
  mt19937 eng(seed());
  while(false)
  {
    N=eng()%100+1;
    vector<int>P(N),Q(N);
    for(int &p:P)p=eng()%100;
    for(int &q:Q)q=eng()%100;
    long long naive=0;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)
    {
      if(P[i]<P[j]&&P[j]<P[k]&&Q[i]<Q[j]&&Q[j]<Q[k])naive++;
    }
    for(int i=0;i<1<<17;i++)Qs[i].clear();
    long long ans=solve(P,Q);
    if(naive==ans)
    {
      cout<<"AC : "<<N<<endl;
      continue;
    }
    cout<<"WA : "<<N<<endl;
    for(int p:P)cout<<p<<" ";cout<<endl;
    for(int q:Q)cout<<q<<" ";cout<<endl;
    cout<<naive<<" "<<ans<<endl;
    return 0;
  }
  cin>>N;
  vector<int>P(N),Q(N);
  for(int i=0;i<N;i++)cin>>P[i];
  for(int i=0;i<N;i++)cin>>Q[i];
  cout<<solve(P,Q)<<endl;
}