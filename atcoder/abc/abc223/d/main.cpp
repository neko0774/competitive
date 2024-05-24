#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> G[1<<18];
int main(){
  int N, M;
  cin >> N >> M;
  int A, B;
  vector<int> count(N, 0);
  for(int i=0;i<M;i++){
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    count[B]++;
  }

  priority_queue<int> q;
  for(int i=0;i<N;i++){
    if(count[i]==0) q.push(-i);
  }
  vector<int> ans;
  while(!q.empty()){
    int x = -q.top();q.pop();
    ans.push_back(x);
    for(auto nx: G[x]){
      count[nx]--;
      if(count[nx]==0)q.push(-nx);
    }
  }
  if(ans.size()==N){
    for(auto a:ans) cout << a+1 << ' ';
  }else{
    cout << -1 << endl;
  }
}