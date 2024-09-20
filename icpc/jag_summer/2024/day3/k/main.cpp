#include<bits/stdc++.h>
using namespace std;


struct dsu{
  vector<int>p;
  dsu(int n):p(n,-1){}
  int leader(int u){return p[u]<0?u:leader(p[u]);}
  bool same(int u, int v){return leader(u)==leader(v);}
  void merge(int u, int v)
  {
    u=leader(u);
    v=leader(v);
    if(u==v)return;
    if(p[u]>p[v])swap(u,v);
    p[u]+=p[v];
    p[v]=u;
  }
  int size(int u){return -p[leader(u)];}
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> pos(N);
  vector<unordered_set<int>> grp(N);

  for(int i = 0; i < N; i++) {
    pos[i] = i;
    grp[i].insert(i);
  }

  dsu uf(N + M);

  auto mrg = [&](int x, int y) -> void {
    int px = pos[x];
    int py = pos[y];
    if(grp[px].size() > grp[py].size()) swap(px, py);
    uf.merge(px, py); // 
    while(!grp[px].empty()) {
      const int z = *grp[px].begin();
      grp[px].erase(z);
      grp[py].insert(z);
      pos[z] = py;
    }
  };

  auto rmv = [&](int x) -> void {
    const int px = pos[x];
    const int sz = grp.size();
    grp[px].erase(x);
    grp.push_back(unordered_set<int>());
    grp[sz].insert(x);
    pos[x] = sz;
    uf.merge(sz, px);
  };

  for(int q = 0; q < M; q++) {
    int t;
    cin >> t;

    for(int i = 0; i < N; i++) {
      cout << pos[i] + 1 << " ";
    } cout << "\n";

    if(t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      mrg(x, y);
    }
    
    else if(t == 2) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      uf.merge(pos[x], pos[y]);
    }

    else if(t == 3) {
      int x;
      cin >> x;
      x--;
      rmv(x);
    }

    else if(t == 4) {
      int x, y;
      cin >> x >> y;
      x--, y--;

      cout << "# " << pos[x] + 1 << " " << pos[y] + 1 << "\n";
      if(pos[x] == pos[y]) {
        cout << "Yes" << "\n";
      }
      else if(uf.same(pos[x], pos[y])) {
        cout << "No" << "\n";
      }
      else {
        cout << "Unknown" << "\n";
      }
    }
  }
}