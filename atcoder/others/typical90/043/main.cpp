#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;
vector<vector<int>> dxy = {{1, 0, 0}, {0, 1, 1}, {-1, 0, 2}, {0, -1, 3}};

void show(vector<vector<vector<int>>> q){
  for(auto xx: q){
    for(auto yy: xx){
      for(auto zz: yy){
        cout << zz << ' ';
      }
      cout << '|';
    }
    cout << endl;
  }
}


int main(){
  int H, W;
  cin >> H >> W;
  int sx, sy, gx, gy;
  cin >> sy >> sx;
  cin >> gy >> gx;
  sx--;
  sy--;
  gx--;
  gy--;
  vector<vector<bool>> S(H, vector<bool>(W, false));
  vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, INF)));
  for(int i=0;i<4;i++){
    dist[sy][sx][i] = 0;
  }
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      char t;
      cin >> t;
      if(t=='.') S[y][x] = true;
    }
  }
  deque<vector<int>> q;
  for(int i=0;i<4;i++){
    vector<int> t = {sx, sy, i};
    q.push_back(t);
  }
  while(!q.empty()){
    int x = q.front()[0], y = q.front()[1], dir = q.front()[2];
    q.pop_front();
    if(x==gx&&y==gy){
      cout << dist[y][x][dir] << endl;
      //show(dist);
      return 0;
    }
    for(vector<int> n: dxy){
      int nx = x+n[0], ny = y+n[1], i = n[2];
      if(!(0<=nx&&nx<W&&0<=ny&&ny<H)||!S[ny][nx]) continue;
          if(i!=dir&&dist[ny][nx][i]>dist[y][x][dir]+1){
            dist[ny][nx][i] = dist[y][x][dir]+1;
            q.push_back({nx, ny, i});
          }else if(i==dir&&dist[ny][nx][i]>dist[y][x][dir]){
            dist[ny][nx][i] = dist[y][x][i];
            q.push_front({nx, ny, i});
          }
    }
  }
}