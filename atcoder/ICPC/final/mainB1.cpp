#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int N;
  cin>>N;
  if(N==0)return false;
  vector<int>A(N),B(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)cin>>B[i];
  int pre=-1;
  int sumA=0,sumB=0;
  int ans=0;
  for(int i=0;i<N;i++)
  {
    sumA+=A[i];
    sumB+=B[i];
    if(sumA>sumB)
    {
      if(pre==1)ans++;
      pre=0;
    }
    else if(sumB>sumA)
    {
      if(pre==0)ans++;
      pre=1;
    }
  }
  cout<<ans<<endl;
  return true;
}

int main(){
  while(solve()){}
}