#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct WeightedGraph{
  
};

template< typename T >
pair< T, int > dfs(const WeightedGraph< T > &g, int idx, int par) {
  pair< T, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    auto cost = dfs(g, e.to, idx);
    cost.first += e.cost;
    ret = max(ret, cost);
  }
  return ret;
}

template< typename T >
T tree_diameter(const WeightedGraph< T > &g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}

int main(){
  int N;
  cin >> N;
  vector<pair<ll, int>> G(N, )
}