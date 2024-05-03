#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

template<typename S, auto op, auto e>
struct segtree{
  segtree(int _n):n(_n)
  {
    log=0;
    while((1<<log)<n)log++;
    sz=1<<log;
    node.resize(2*sz,e());
  }
  void set(int p, S x)
  {
    p+=sz;
    node[p]=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  S prod(int l, int r)
  {
    l+=sz,r+=sz;
    S pl=e(),pr=e();
    while(l<r)
    {
      if(l&1)pl=op(pl,node[l++]);
      if(r&1)pr=op(node[--r],pr);
      l>>=1,r>>=1;
    }
    return op(pl,pr);
  }
  S all_prod(){return node[1];}
private:
  int n,log,sz;
  vector<S>node;
  void update(int p){node[p]=op(node[2*p],node[2*p+1]);}
};
long long op(long long a, long long b){return a+b;}
long long e(){return 0;}
long long inv_num(vector<int>v)
{
  vector<int>B=v;
  sort(B.begin(),B.end());
  B.erase(unique(B.begin(),B.end()),B.end());
  assert(B.size()==v.size());
  segtree<long long,op,e>seg(B.size());
  long long res=0;
  for(auto x:v)
  {
    x=lower_bound(B.begin(),B.end(),x)-B.begin();
    res+=seg.prod(x,B.size());
    seg.set(x,1);
  }
  return res;
}
using S = array<int, 2>;
S op2(S x, S y) {
  return S{x[0] + y[0], x[1] + y[1]};
}
S e2() {
  return S{0, 0};
}
long long weighted(vector<pair<int,int>>V)
{
  const int N=V.size();
  long long ans=0;
  for(int i=1;i<N;i++)for(int j=0;j<i;j++)
  {
    ans+=(V[j].first>V[i].first)*min(V[i].second,V[j].second);
  }
  return ans;
}
bool solve()
{
  int N;
  cin>>N;
  if(N==0)return 0;
  vector<int>P(N);
  for(int i=0;i<N;i++)cin>>P[i];
  long long ans=inv_num(P);
  vector<pair<int,int>>A;
  for(int p:P)
  {
    if(A.empty()||A.back().first+1!=p)A.push_back(make_pair(p,1));
    else A.back().second++;
  }
  ans+=weighted(A);
  cout<<ans<<"\n";
  return 1;
}
int main(){
  while(solve()){}
}