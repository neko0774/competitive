#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
#include<atcoder/fenwicktree>
using mint = atcoder::modint998244353;
const ll mod = 998244353;

template<typename T>
T mod_pow(T x, T power, T &mod){
  T ret = 1;
  while(power){
    if(power&1)ret *= x, ret%=mod;
    x *= x;
    x %= mod;
    power>>=1;
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  set<int> comp;
  for(int i=0;i<N;i++){
    cin >> A[i];
    comp.insert(A[i]);
  }
  
  map<int, int> ch;
  vector<mint> cnt(N);
  for(auto a: A)ch[a]=0;
  int sz=0;
  for(auto &[a, b]: ch) b=sz++;
  for(int i=0;i<N;i++) A[i]=ch[A[i]];
  atcoder::fenwick_tree<mint> fw(N+1);
  mint div = mint(2).pow(mod-2);
  mint ans;
  for(int k=0;k<N;k++){
    if(k>0)ans += mint(2).pow(k)*fw.sum(0, A[k]+1).val();
    fw.add(A[k], mint(div).pow(k+1));
  }
  cout << ans.val() << endl;
}