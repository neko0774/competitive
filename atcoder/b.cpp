#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;

bool solve(){
  int H,W;
  cin>>H>>W;
  if(H==0&&W==0)return 0;
  int K=H+W-1;
  vector<vector<int>>MH(H),MW(W);
  MH[0].push_back(0);
  MW[0].push_back(0);
  vector<int>R(K+1,0),C(K+1,0),X(K+1,0);
  for(int i=1;i<=K;i++)
  {
    cin>>R[i]>>C[i]>>X[i];
    R[i]--,C[i]--;
    MH[R[i]].push_back(i);
    MW[C[i]].push_back(i);
  }
  atcoder::dsu uf(K+1);
  for(int i=0;i<H;i++)
  {
    for(int x:MH[i])uf.merge(x,MH[i].back());
  }
  for(int i=0;i<W;i++)
  {
    for(int x:MW[i])uf.merge(x,MW[i].back());
  }
  cout<<(uf.groups().size()==1?"YES":"NO")<<"\n";
  return 1; 
}


int main(){
  while(solve()){}
}