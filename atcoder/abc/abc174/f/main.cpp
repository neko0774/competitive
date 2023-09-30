#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define ll long long

template<typename T>
struct BIT{
  int N;
  vector<T> data = vector<T>(N);
  BIT(int _N=0): data(_N){}

  void add(int i, T x){
    i++;
    while(i<=data.size()){
      data[i-1]+=x;
      i += i&-i;
    }
  }

  T rsum(int r){
    T s = 0;
    while(r>0){
      s += data[r-1];
      r -= r&-r;
    }
    return s;
  }

  T sum(int l, int r){
    //[l, r)
    return rsum(r)-rsum(l);
  }
};


int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> C(N);
  for(int i=0;i<N;i++){
    cin >> C[i];
  }
  vector<vector<int>> query;
  int l, r;
  for(int i=0;i<Q;i++){
    cin >> l >> r; 
    query.push_back({l-1, r-1, i});
  }
  unordered_map<int, int> last_seen;
  for(int i=0;i<N;i++){
    if(last_seen.count(C[i])>0){
      query.push_back({last_seen[C[i]], i, -1});
    }
    last_seen[C[i]] = i;
  }

  sort(query.begin(), query.end(), [](vector<int> &a, vector<int> &b){return (a[1]==b[1])?a[2]<b[2]:a[1]<b[1];});
  BIT<ll> fw(N);
  vector<ll> ans(Q, 0);
  for(auto v: query){
    int l = v[0], r = v[1], idx = v[2];
    if(idx==-1){
      fw.add(l, 1);
    }else{
      ll mi = fw.sum(l, r);
      ans[idx]=r-l+1-fw.sum(l, r);
    }
  }
  for(auto a: ans) cout << a << endl;
}