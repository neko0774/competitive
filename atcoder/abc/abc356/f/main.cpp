#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct dsu{
  int N;
  vector<int> root, size, csize;
  dsu(int _N=0): root(_N), size(_N), csize(_N){
  for(int i=0;i<_N;i++){
    root[i]=i;
    size[i]=1;
    csize[i]=1;
  }
  N = _N;
  }

  int merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return -1;
    if (size[y]>size[x]) swap(x, y);
    root[y] = root[x];
    size[y] += size[x];
    csize[y] += csize[x];
    csize[x] = csize[y];
    return root[y];
  }

  bool same(int x, int y){
    return find(x)==find(y);
  }

  int find(int x){
    if (root[x]==x) return x;
    root[x] = find(root[x]);
    return root[x];
    
  }

  int g_size(int x){
    return csize[find(x)];
  }

  vector<vector<int>> groups(){
    vector<vector<int>> keep(N, vector<int>());
    vector<vector<int>> ret;
    for(int i=0;i<N;i++){
      keep[find(i)].push_back(i);
    }
    for(int i=0;i<N;i++){
      if(keep[i].size()!=0){
        ret.push_back(keep[i]);
      }
    }
    return ret;
  }

  void debug(){
    auto G = groups();
    for(auto g: G){
      cout << '{';
      int head = find(g[0]);
      cout << head << ' ' << csize[head] << '|';
      for(auto x: g) cout << x << ' ';
      cout <<  '}' << endl;
    }
  }
};

int main(){
  ll Q, K;
  cin >> Q >> K;
  unordered_map<ll, ll> conv;
  unordered_set<ll> V;
  vector<pair<ll, ll>> query;
  ll q, x;
  for(int i=0;i<Q;i++){
    cin >> q >> x;
    query.push_back(make_pair(q, x));
    V.insert(x);
  } 
  vector<ll> VV;
  for(auto v:V)VV.push_back(v);
  sort(VV.begin(), VV.end());
  for(int i=0;i<VV.size();i++){
    conv[VV[i]] = i;
    cout << VV[i] << ' ' << i << endl;
  }
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  set<ll> exist;
  dsu uf(VV.size());
  for(auto [q, x]: query){
    if(q==1){
      exist.insert(x);
      cout << max(0LL, x-K) << ' ' << x+K << endl;
      
      uf.merge(conv[x], l);
      uf.merge(conv[x], r);
    }else{
      uf.debug();
      cout << uf.g_size(x) << endl;
    }
  }
}