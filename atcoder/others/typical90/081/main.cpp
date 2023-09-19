#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
void chmax(T &A, T B){
  if(B>A) A = B;
}


template<typename T>
struct cumsum2d{
  vector<vector<T>> data;
  cumsum2d(int W, int H): data(H+1, vector<T>(W+1, 0)){}

  void add(int x, int y, T z){
    data[y][x]+=z;
  }

  void build(){
    for(int y=0;y<data.size()-1;y++){
      for(int x=0;x<data[0].size()-1;x++){
        data[y+1][x+1] += data[y][x+1]+data[y+1][x]-data[y][x];
      }
    }
  }

  T query(int sx, int sy, int gx, int gy){
    gx++;gy++;
    if(sx<0||sy<0||gy>=data.size()||gx>=data[0].size()) return 0;
    return data[gy][gx]-data[sy][gx]-data[gy][sx]+data[sy][sx];
  }
};

int main(){
  int N; ll K;
  int X, Y;
  cin >> N >> K;
  cumsum2d<int> S(5002, 5002);
  for(int i=0;i<N;i++){
    cin >> X >> Y;
    S.add(X, Y, 1);
  }
  S.build();
  int ans = 0;
  for(int y=0;y<5002;y++){
    for(int x=0;x<5002;x++){
      chmax(ans, S.query(x, y, x+K, y+K));
      //cout << x << ' ' << y << ' ' << endl;
    }
  }
  cout << ans << endl;
}