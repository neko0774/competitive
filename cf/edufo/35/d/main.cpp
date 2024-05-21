#include<bits/stdc++.h>
using namespace std;


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
  int N, M;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    A[i]--;
  }
  int Q;
  cin >> Q;
  int l, r;
  int cntinv = 0;
  BIT<int> count(N);
  for(int i=0;i<N;i++){
    count.add(A[i], 1);
    cntinv += count.rsum(A[i]+1);
  }
  cntinv %= 2;
  for(int i=0;i<Q;i++){
    cin >> l >> r;
    cntinv += (r-l+1)/2;
    cntinv%= 2;
    if(cntinv%2==0) cout << "even" << endl;
    else cout << "odd" << endl;
  }
}