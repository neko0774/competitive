#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int N;
  cin>>N;
  if(N==0)return false;
  vector<long long>X(N),Y(N),Z(N);
  for(int i=0;i<N;i++)
  {
    cin>>X[i]>>Y[i]>>Z[i];
    X[i]*=2;
    Y[i]*=2;
    Z[i]*=2;
  }
  map<tuple<long long,long long,long long,long long>,long long>mp;
  long long ans=0;
  for(int i=0;i<N;i++)for(int j=0;j<i;j++)
  {
    long long mx=(X[i]+X[j])/2;
    long long my=(Y[i]+Y[j])/2;
    long long mz=(Z[i]+Z[j])/2;
    long long dx=X[i]-X[j];
    long long dy=Y[i]-Y[j];
    long long dz=Z[i]-Z[j];
    auto T=make_tuple(mx,my,mz,dx*dx+dy*dy+dz*dz);
    ans+=mp[T];
    mp[T]++;
  }
  cout<<ans<<endl;
  return 1;
}

int main(){
  while(solve()){}
}