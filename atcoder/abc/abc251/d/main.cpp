#include <bits/stdc++.h>
using namespace std;

int main(){
  int W;
  cin >> W;
  int cnt = 0;
  cout << 298 << endl;
  for(int i=1;i<100;i++){
    cout << i << ' ';
    cnt++;
  }
  for(int i=100;i<10000;i+=100){
    cout << i << ' ';
    cnt++;
  }
  for(int i=10000;i<1000000;i+=10000){
    cout << i << ' ';
    cnt++;
  }
  cout << 1000000 << endl;
}