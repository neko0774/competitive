#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long> c1(N+1, 0), c2(N+1, 0);
  for(int i=0;i<N;i++){
    long c,p;
    cin >> c >> p;
    if(c==1)c1[i+1]+=p;
    else c2[i+1]+=p;
    c1[i+1]+=c1[i];
    c2[i+1]+=c2[i];
  }
  int Q; cin >> Q;
  for(int i=0;i<Q;i++){
    int r, l;
    cin >> l >> r;
    cout << c1[r]-c1[l-1] << ' ' << c2[r]-c2[l-1] << '\n';
  }
}