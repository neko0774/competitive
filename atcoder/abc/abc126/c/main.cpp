#include <bits/stdc++.h>
using namespace std;
#define double long double
int count(int x, int K){
  int ret = 0;
  while(x<K){
    x *= 2;
    ret++;
  }
  return ret;
}


int main(){
  int N, K;
  cin >> N >> K;
  double ans = 0;
  for(int i=1;i<N+1;i++){
    int cnt = count(i, K);
    double c = 1;
    for(int i=0;i<cnt;i++){
      c *= 0.5;
    }
    ans += c;
  }
  cout << setprecision(20) << ans/N << endl;
}