#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

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
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;

bool solve(){
  int H,W;
  cin>>H>>W;
  if(H==0&&W==0)return 0;
  int K=H+W-1;
  vector<vector<int>>MH(H),MW(W);
  MH[0].push_back(0);
  MW[0].push_back(0);
  vector<int>R(K+1,0),C(K+1,0),X(K+1,0);
  for(int i=1;i<=K;i++)
  {
    cin>>R[i]>>C[i]>>X[i];
    R[i]--,C[i]--;
    MH[R[i]].push_back(i);
    MW[C[i]].push_back(i);
  }
  atcoder::dsu uf(K+1);
  for(int i=0;i<H;i++)
  {
    for(int x:MH[i])uf.merge(x,MH[i].back());
  }
  for(int i=0;i<W;i++)
  {
    for(int x:MW[i])uf.merge(x,MW[i].back());
  }
  cout<<(uf.groups().size()==1?"YES":"NO")<<"\n";
  return 1; 
}


int main(){
  while(solve()){}
}
