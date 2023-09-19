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

  int ssize(int x){return size[x];}

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
  dsu uf(N); 
  vector<vector<ll>> query;
  vector<ll> cos(N, -1);
  for(int i=0;i<Q;i++){
    cin >> T >> X >> Y >> V;
    X--;Y--;
    query.push_back({T, X, Y, V});
    if(T==0){
      cos[X] = V;
    }
  }
  vector<ll> A(N, -1);
  int x;
  for(int i=0;i<N;i++){
    x = i;
    if(A[x]!=-1) continue;
    A[x] = 0;
    while(x<N){
      if(cos[x]!=-1){
        A[x+1] = cos[x]-A[x];
        x++;
      }else break;
    }
  }

  for(int i=0;i<Q;i++){
    int T = query[i][0], X = query[i][1], Y = query[i][2];
    ll Z = query[i][3];
    if(T==0){
      uf.merge(X, Y);
    }else{
      if(!uf.same(X, Y)) cout << "Ambiguous" << endl;
      else cout << A[Y]+((Y-X)%2==0?(Z-A[X]):-(Z-A[X])) << endl;
    }
  }
}