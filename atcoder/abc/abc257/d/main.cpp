#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<typename U>
void show(vector<U> A){
  for(U a: A) cout << a << ' ';
  cout << endl;
}

bool search(int s, ll S, vector<vector<ll>> &jumps){
  int N = jumps.size();
  vector<bool> seen(N, false);
  seen[s] = true;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int x = q.front();q.pop();
    for(int nx=0;nx<N;nx++){
      if(!seen[nx]&&S*jumps[x][2]>=abs(jumps[x][1]-jumps[nx][1])+abs(jumps[x][0]-jumps[nx][0])){
        q.push(nx);
        seen[nx] = true;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(!seen[i]) return false;
  }
  return true;
}

bool good(ll S, vector<vector<ll>> &jumps){
  ll N = jumps.size();

  for(int x=0;x<N;x++){
    //starting point x
    if(search(x, S, jumps)) return true;
  }
  return false;
}

int main(){
  int N;
  cin >> N;
  vector<vector<ll>> jumps(N, vector<ll>(3));
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      cin >> jumps[i][j];
    }
  }

  //S*P -> overflow
  ll ok = 1e10, ng = 0;
  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;

    if(good(mid, jumps)) ok = mid;
    else ng = mid;   
  }
  cout << ok << endl;
}