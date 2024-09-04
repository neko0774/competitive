#include<bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
vector<int> wx = {0, 1, 0, -1};
vector<int> wy = {1, 0, -1, 0};

bool ok(int x, int y, int H, int W){
  return 0<=x&&x<W&&0<=y&&y<H;
}

dsu connect(int H, int W, vector<string> &G){
  dsu uf(H*W+1);
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      //cout << x << ' ' << y << ' ' << G[y][x] <<  endl;
      if(G[y][x]=='.'){
        for(int i=0;i<4;i++){
          int nx = x + wx[i];
          int ny = y + wy[i];
          //cout << nx << ' ' << ny << ' ' << ok(nx, ny, W, H) << endl;
          if(ok(nx, ny, H, W)&&G[ny][nx]==G[y][x]) uf.merge(ny * W + nx, y * W + x);
          else if(!ok(nx, ny, H, W)) uf.merge(H * W, y * W + x);
        }
      }else{
        for(int i=-1;i<=1;i++){
          for(int j=-1;j<=1;j++){
            int nx = x + i;
            int ny = y + j;
            if(nx==x&&ny==y) continue;
            if(ok(nx, ny, H, W)&&G[ny][nx]==G[y][x]) uf.merge(ny * W + nx, y * W + x);
          }
        }
      }
    }
  }
  return uf;
}

vector<unordered_set<int>> count_cc(int H, int W, dsu &uf, vector<string> &G){
  vector<unordered_set<int>> ret(3);
  for(int x=0;x<W;x++){
    for(int y=0;y<H;y++){
      int h = uf.leader(y*W+x);
      if(G[y][x]=='.') ret[0].insert(h);
      else ret[1].insert(h);

      if((x==0||y==0||x==W-1||y==H-1)&&G[y][x]=='#'){
        ret[2].insert(h);
      }
    }
  }
  return ret;
}

void print(vector<unordered_set<int>> &A){
  for(auto &a: A){
    for(auto aa: a) cout << aa << ' ';
    cout << endl;
  }
  cout << endl;
}


void show(dsu uf){
  for(auto g: uf.groups()){
    for(auto x: g) cout << x << ' ';
    cout << endl;
  }
  cout << endl;
}

bool solve(){
  int H1, W1, H2, W2;
  cin >> H1 >> W1;
  if(H1==0) return false;
  vector<string> G1(H1);
  for(int i=0;i<H1;i++){
    cin >> G1[i];
  }
  cin >> H2 >> W2;
  vector<string> G2(H2);
  for(int i=0;i<H2;i++){
    cin >> G2[i];
  }
  dsu uf1 = connect(H1, W1, G1);
  dsu uf2 = connect(H2, W2, G2);
  //show(uf1);
  //show(uf2);
  auto c1 =  count_cc(H1, W1, uf1, G1);
  auto c2 =  count_cc(H2, W2, uf2, G2);
  //print(c1);
  //print(c2);
  if(c1[0].size()==c2[0].size()&&c1[1].size()==c2[1].size()&&c1[2].size()==c2[2].size()){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return true;
}

int main(){
  while(solve()){}
}