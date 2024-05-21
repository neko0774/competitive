#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> G[1<<17];
vector<int> size;
vector<bool> used;

int total = 0;
int cent;



void dfs(int x, int par){
  bool ok = true;
  int ret = 0;
  for(auto nx:G[x]){
    if(nx==par) continue;
    int now = dfs(nx, par);
    if(2*now>total) now = false; 
    size[nx] = now;
    ret += now;
  }
  if(2*(total-ret)>total)now = false;
  if(now) cent = x;
}

int main(){
  int N;
  cin >> N;
  int A, B;
  size.resize(N);
  is_removed.resize(N, false);
  for(int i=0;i<N-1;i++){
    cin >> A >> B;
    A--;
    B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  vector<int> ans(N, -1);
  vector<int> next;
  queue<vertex<int>> centre;
  while(!centre.empty()){
    auto [x,par, sz] = centre.front();
    ans[x] = par;
    centre.pop();
    next.clear();
    if(par!=-1){
      for(auto nx: G[x]){
        if(par!=nx)next.push_back(nx);
      }
    }
    size = vector<int>(N);
  }
  
}