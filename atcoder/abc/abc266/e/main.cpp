#include <bits/stdc++.h>
using namespace std;
vector<double> pos(1000, -1.0);

double solve(int x){
  if(x==1) return 3.5;
  if(pos[x]!=-1.0) return pos[x];
  double ret = 0.0;
  for(int i=1;i<=6;i++){
    ret += max(i+0.0, solve(x-1))/6;
  }
  pos[x] = ret;
  return ret;
}

int main(){
  int N;
  cin >> N;
  cout << solve(N) << endl;
}