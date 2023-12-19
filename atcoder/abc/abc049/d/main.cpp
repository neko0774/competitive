#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dsu{
  int N;
  vector<int> root, size;
  dsu(int _N=0): root(_N), size(_N){
  for(int i=0;i<_N;i++){
    root[i]=i;
  }
  }

  int merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return -1;
    if (size[y]>size[x]) swap(x, y);
    root[y] = root[x];
    size[y] += size[x];
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
};

int main(){
  ll N, K, L;
  cin >> N >> K >> L;
  dsu road(N);
  dsu train(N);
  int u, v;
  for(int i=0;i<K;i++){
    cin >> u >> v;
    u--;
    v--;
    road.merge(u, v);
  }
  for(int i=0;i<L;i++){
    cin >> u >> v;
    u--;
    v--;
    train.merge(u, v);
  }

  vector<ll> ans(N, 0);
  unordered_map<ll, ll> cnt;
  for(int i=0;i<N;i++){
    ll a = road.find(i);
    ll b = train.find(i);
    cnt[a*N+b]++;
  }
  for(int i=0;i<N;i++){
    ll a = road.find(i);
    ll b = train.find(i);
    cout << cnt[a*N+b] << ' ';
  }

}