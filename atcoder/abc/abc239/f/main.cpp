#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct dsu{
  int N;
  vector<int> root, size;
  dsu(int _N=0): root(_N), size(_N){
  for(int i=0;i<_N;i++){
    root[i]=i;
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
  int N, M;
  cin >> N >> M;
  vector<int> D(N);
  int cnt = 0;
  for(int i=0;i<N;i++){
    cin >> D[i];
    cnt += D[i];
  }
  int A, B;
  dsu uf(N);
  for(int i=0;i<M;i++){
    cin >> A >> B;
    A--;
    B--;
    uf.merge(A, B);
    D[A]--;
    D[B]--;
  }
  for(auto d: D){
    if(d<0||cnt!=2*(N-1)){
      cout << -1 << endl;
      return 0;
    }
  }
  vector<vector<int>> to_add(N, vector<int>());
  set<pair<int, int>> comp;
  for(auto G: uf.groups()){
    int head = uf.find(G[0]);
    int cnt = 0;
    for(auto g: G){
      cnt += D[g];
      for(int i=0;i<D[g];i++)to_add[head].push_back(g);
    }
    if(cnt==0){
      cout << -1 << endl;
      return 0;
    }
    comp.emplace(cnt, head);
  }
  vector<pair<int, int>> ans;
  while(comp.size()>1){
    auto head = comp.begin();
    int a = head->second;
    comp.erase(head);
    auto tail = comp.end();tail--;
    int b = tail->second;
    comp.erase(tail);
    ans.push_back(make_pair(to_add[a].back(), to_add[b].back()));
    to_add[a].pop_back();to_add[b].pop_back();
    to_add[b].insert(to_add[b].end(), to_add[a].begin(), to_add[a].end());
    comp.emplace(to_add[b].size(), b);
  }
  for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << endl;
}
