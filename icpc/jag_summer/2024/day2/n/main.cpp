#include<bits/stdc++.h>
using namespace std;
template<long long MOD>
struct modint {
  modint(): x(0){}
  modint(long long v): x(v % MOD){
    if (x < 0) x += MOD;
  }
  long long x;
  long long val() const {return x;}
  static constexpr long long mod() noexcept {return MOD; }
  friend modint operator+(modint a, modint b){ return a.x + b.x;}
  friend modint operator-(modint a, modint b){ return a.x - b.x;}
  friend modint operator*(modint a, modint b){ return a.x * b.x;}
  friend modint operator/(modint a, modint b){ return a.x * b.inv();}
  friend modint operator+=(modint &a, modint b){ return a = a + b;}
  friend modint operator-=(modint &a, modint b){ return a = a - b;}
  friend modint operator*=(modint &a, modint b){ return a = a * b;}
  friend modint operator/=(modint &a, modint b){ return a = a / b;}
  friend modint operator==(modint a, modint b){ return a.x == b.x;}
  friend modint operator!=(modint a, modint b){ return a.x != b.x;}
  modint operator+() const {return *this; }
  modint operator-() const {return modint() - *this; }
  modint pow(long long k) const{
    modint a = x, res = 1;
    while(k > 0){
      if(k & 1) res *= a;
      a *= a;
      k >>= 1;
    }
    return res;
  }
  modint inv() const{
    long long a = x, b = MOD;
    long long u = 1, v = 0;
    while (b > 0){
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return u;
  }
};
using mint=modint<998244353>;
int N,A[2<<17];
int ett[1<<20];
int dp[1<<20],pre[1<<20];
mint ep[2<<17];
void init()
{
  for(int i=0;i<1<<20;i++)
  {
    ett[i]=-1;
    dp[i]=0;
    pre[i]=-1;
  }
  for(int i=2;i<1<<20;i++)if(ett[i]==-1)
  {
    for(int j=i;j<1<<20;j+=i)ett[j]=i;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  cin>>N;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)
  {
    vector<int>F;
    while(A[i]>1)
    {
      int p=ett[A[i]];
      F.push_back(p);
      while(A[i]%p==0)A[i]/=p;
    }
    int L=0;
    for(int p:F)L=max(L,dp[p]);
    set<int>pres;
    for(int p:F)
    {
      if(dp[p]==L)pres.insert(pre[p]);
      dp[p]=L+1;
      pre[p]=i;
    }
    if(L==0)ep[i]=1;
    else
    {
      for(int j:pres)if(j!=-1)ep[i]+=ep[j];
    }
  }
  int L=*max_element(dp,dp+(1<<20));
  if(L<=1)
  {
    cout<<1<<"\n"<<N<<"\n";
    return 0;
  }
  set<int>idx;
  for(int i=0;i<1<<20;i++)if(dp[i]==L)idx.insert(pre[i]);
  mint ans=0;
  for(int i:idx)if(i!=-1)ans+=ep[i];
  cout<<L<<"\n"<<ans.val()<<"\n";
}