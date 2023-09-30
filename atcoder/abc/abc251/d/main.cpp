#include <bits/stdc++.h>
using namespace std;

int main(){
  int W;
  cin >> W;
  int s = 1;
  cout << 99*3+1 << endl;
  for(int i=0;i<3;i++){
    for(int j=1;j<100;j++){
      cout << s*j << ' ';
    }
    s *= 100;
  }
  cout << 1000000 << endl;
}