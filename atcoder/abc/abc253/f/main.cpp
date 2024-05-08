#include <bits/stdc++.h>
using namespace std;

struct BIT{
  int N;
  vector<long> data = vector<long>(N);
  BIT(int _N=0): data(_N){}

  void add(int i, long x){
    i++;
    while(i<=data.size()){
      data[i-1]+=x;
      i += i&-i;
    }
  }

  long rsum(int r){
    long ret = 0;
    while(r>0){
      ret += data[r-1];
      r -= r&-r;
    }
    return ret;
  }

  long sum(int l, int r){
    return rsum(r)-rsum(l);
  }
};


int main(){
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> q(N, vector<int>(4));
  BIT bit(N);
  for(int i=0;i<Q;i++){
    cin >> q[i][0];
    if(q[i][0]==1){
      cin >> q[i][1] >> q[i][2] >> q[i][3];
    }else{
      cin >> q[i][1] >> q[i][2];
    }
  }


}