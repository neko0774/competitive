#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> cnt(N, 0);
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    cnt[max(a, b)-1]++;
  }
  int ans=0;
  for(int x=0;x<N;x++){
    if(cnt[x]==1)ans++;
  }
  cout << ans << endl;
}