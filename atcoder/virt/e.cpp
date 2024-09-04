#include<bits/stdc++.h>
using namespace std;

pair<int, int> count(int l, int x){
  if(l == 0) return make_pair(0, 1);
  int ret = 0;
  x--;
  auto [meat, size] = count(l - 1, x);
  int ret_size = size * 2 + 3;
  x -= size;
  ret += meat;
  x--;
  if(x < size) auto [meat, size] = count(l - 1, x);
  ret += meat;
  return make_pair(ret, ret_size);
}

int main(){
  int N, X;
  cin >> N >> X;
  auto[ans, a] = count(N, X);
  cout << ans << endl;
}