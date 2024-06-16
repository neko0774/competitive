#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int H,W;
  cin>>H>>W;
  if(H==0&&W==0)return 0;
  int K=H+W;
  vector<vector<int>>MH(H),MW(W);
  vector<int>R(K-1,0),C(K-1,0),X(K-1,0);
  queue<int>q;
  for(int i=0;i<K-1;i++)
  {
    cin>>R[i]>>C[i]>>X[i];
    R[i]--,C[i]--;
    MH[R[i]].push_back(i);
    MW[C[i]].push_back(i);
    if(R[i]==0)q.push(i);
  }
  const int INF=1<<28;
  vector<int>ansH(H,INF),ansW(W,INF);
  ansH[0]=0;
  while(!q.empty())
  {
    int i=q.front();
    q.pop();
    int r=R[i],c=C[i];
    assert(ansH[r]!=INF||ansW[c]!=INF);
    if(ansH[r]!=INF)
    {
      if(ansW[c]!=INF&&ansW[c]!=X[i]-ansH[r])
      {
        cout<<"NO"<<"\n";
        return 1;
      }
      ansW[c]=X[i]-ansH[r];
    }
    else
    {
      if(ansH[r]!=INF&&ansH[r]!=X[i]-ansW[c])
      {
        cout<<"NO"<<"\n";
        return 1;
      }
      ansH[r]=X[i]-ansW[c];
    }
    for(int j:MH[r])if(j!=i)
    {
      if(ansH[R[j]]==INF||ansW[C[j]]==INF)q.push(j);
    }
    for(int j:MW[c])if(j!=i)
    {
      if(ansH[R[j]]==INF||ansW[C[j]]==INF)q.push(j);
    }
  }
  for(int i=0;i<K-1;i++)if(ansH[R[i]]+ansW[C[i]]!=X[i])
  {
    cout<<"NO"<<"\n";
    return 1;
  }
  for(int i=0;i<H;i++)if(ansH[i]==INF)
  {
    cout<<"NO"<<"\n";
    return 1;
  }
  for(int i=0;i<W;i++)if(ansW[i]==INF)
  {
    cout<<"NO"<<"\n";
    return 1;
  }
  cout<<"YES"<<"\n";
  return 1; 
}


int main(){
  while(solve()){}
}