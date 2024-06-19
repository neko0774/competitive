#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef unsigned long long ull;
unordered_set<int> ans;
unordered_set<ull> seen;
vector<string> S(8);
int memo = 0;
ull cur = 0;
int a = 0;
vector<ll> dx={1,0,-1,0};
vector<ll> dy={0,1,0,-1};

bool ok(int x, int y, int N){
  if(0<=x&&0<N&&0<=y&&y<N) return true;
  return false;
}


void calc(int cx, int cy, int &K, int &N){
  if(seen.count(cur)>0) return;
  seen.insert(cur);
  if(memo==K){
    ans.insert(cur);
    a++;
    return;
  }
  vector<pair<int, int>> check;
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      if(S[y][x]!='.') continue;
      bool connect = false;
      for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(ok(nx, ny, N)&&S[ny][nx]=='r') connect = true;
      }
      if(connect) check.push_back(make_pair(x, y));
    }
  }
  for(auto [nx, ny]: check){
    S[ny][nx] = 'r';
    memo++;
    cur += ull(1)<<(ny*N+nx);
    calc(nx, ny, K, N);
    S[ny][nx] = '.';
    memo--;
    cur -= ull(1)<<(ny*N+nx);
  }
}

int main(){
  int N, K;
  cin >> N >> K;
  S.resize(N);
  for(int i=0;i<N;i++){
    cin >> S[i];
  }
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      if(S[y][x]=='.'){
        memo = 1;
        cur = ull(1)<<(y*N+x);

        S[y][x] = 'r';
        calc(x, y, K, N);
        S[y][x] = '.';
      }
    }
  }
  cout << a << endl;
}