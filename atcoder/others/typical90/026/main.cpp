#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<vector<int>> G(N, vector<int>());
  for(int i=0;i<N-1;i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  queue<int> q;
  q.push(0);
  vector<int> A, B;
  vector<int> seen(N, -1);
  seen[0] = 1;
  while(!q.empty()) {
    int x = q.front();q.pop();
    if(seen[x]) A.push_back(x);
    else B.push_back(x);
    for(auto nx: G[x]){
      if(seen[nx]==-1){
        seen[nx] = 1-seen[x];
        q.push(nx);
      }
    }
  }
  if(A.size()>=N/2)for(int i=0;i<N/2;i++)cout << A[i]+1 << ' ';
  else for(int i=0;i<N/2;i++)cout << B[i]+1 << ' ';
}