#include<bits/stdc++.h>
using namespace std;
#define ll long long

void show(vector<ll> A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}
void showp(vector<pair<ll, ll>> A){
  for(auto a: A) cout << a.first << ' ' << a.second << '|';
  cout << endl;
}

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


void chmax(ll &A, ll B){
  if(B>A) A = B;
}

int main(){
  int N, Q;
  cin >> N;
  cin >> Q;
  ll T, X, Y, V;
  vector<vector<ll>> query, add;
  unordered_map<int, vector<ll>> res;
  unordered_set<int> s;
  vector<vector<pair<ll, ll>>> G(N, vector<pair<ll, ll>>());
  dsu uf(N); 
  for(int i=0;i<Q;i++){
    cin >> T >> X >> Y >> V;
    X--;Y--;
    query.push_back({T, X, Y, V});
    if(T==0){
      G[X].push_back(make_pair(Y, V));
      G[Y].push_back(make_pair(X, V));
    }else{s.insert(X)};
  }
  vector<bool> done(N, false);
  for(int x=0;x<N;x++){
    if(result[x]!=-1&&!done[x]){
      done[x] = true;
      cout << x << endl;
      queue<int> q;
      q.push(x);
      while(!q.empty()){
        int x = q.front();q.pop();
        for(auto nx: G[x]){
          if(!done[nx.first]&&result[nx.first]==-1){
            done[nx.first] = true; 
            q.push(nx.first);
            result[nx.first] = nx.second-result[x];
          }
        }
      }
    }
  }
  cout << endl;
  cout << endl;
  show(result);
  for(auto q: query){
    if(q[0]==0){
      uf.merge(q[1], q[2]);
    }else{
      if(uf.same(q[1], q[2])) cout << result[q[2]] << endl;
      else cout << "Ambiguous" << endl;
    }
  }
}