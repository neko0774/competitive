#include <iostream>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  int ans;
  
  if(H==1||W==1) ans = H*W;
  else ans = ((H+1)/2)*((W+1)/2);

  cout << ans << '\n';
}