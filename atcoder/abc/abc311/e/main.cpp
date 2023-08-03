#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



int main(){
  int H, W, N;
  cin >> H >> W >> N;
  unordered_set<int> A;
  for(int i=0;i<N;i++){
    int a, b;//h, w
    cin >> a >> b;
    a--;
    b--;
    A.insert(a*5000+b);
  }
  long ans=0;
  vector<vector<long>> count(H+1, vector<long>(W+1, 0));
  for(int y=H-1;y>=0;y--){
    for(int x=W-1;x>=0;x--){
      if(A.count(y*5000+x)==0){
        count[y][x] = min(count[y+1][x+1], min(count[y+1][x], count[y][x+1]))+1;
        ans += count[y][x];
      }
    }
  }
  cout << ans << endl;
}