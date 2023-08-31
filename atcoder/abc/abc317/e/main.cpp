#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dxy={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void show(vector<vector<char>> A){
  for(int y=0;y<A.size();y++){
    for(int x=0;x<A[0].size();x++){
      cout << A[y][x];
    }
    cout << endl;
  }
}




int main(){
  ll H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      cin >> A[y][x];
    }
  }
  ll sx=-1, sy=-1;
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      if(A[y][x]=='>'){
        for(int i=x+1;i<W;i++){
          if(A[y][i]=='.'||A[y][i]=='*')A[y][i]='*';
          else break;
        }
      }else if(A[y][x]=='^'){
        for(int i=y-1;i>=0;i--){
          if(A[i][x]=='.'||A[i][x]=='*')A[i][x]='*';
          else break;
        }
      }else if(A[y][x]=='<'){
        for(int i=x-1;i>=0;i--){
          if(A[y][i]=='.'||A[y][i]=='*')A[y][i]='*';
          else break;
        } 
      }else if(A[y][x]=='v'){
        for(int i=y+1;i<H;i++){
          if(A[i][x]=='.'||A[i][x]=='*')A[i][x]='*';
          else break;
        }
      }else if(A[y][x]=='S'){
        sx = x;
        sy = y;
      }
    }
  }
  if(sx==-1){return 0;}
  deque<pair<ll, ll>> q;
  q.push_back(make_pair(sx, sy));
  vector<vector<ll>> dist(H, vector<ll>(W, -1));
  dist[sy][sx]=0;
  //show(A);
  while(!q.empty()){
    ll x = q.front().first, y=q.front().second;
    q.pop_front();
    //cout << x << ' ' << y << endl;
    for(auto dd: dxy){
      ll nx = x+dd[0], ny=y+dd[1];
      //cout << nx << ' ' << ny << ' ' << 1 << endl;
      if(0<=nx&&nx<W&&0<=ny&&ny<H&&dist[ny][nx]==-1&&(A[ny][nx]=='.'||A[ny][nx]=='G')){
        if(A[ny][nx]=='G'){
          cout << dist[y][x]+1 << endl;
          return 0;
        }else{
          dist[ny][nx] = dist[y][x]+1;
          q.push_back(make_pair(nx, ny));
        }
      }
    }
  } 
  cout << -1 << endl;
}