#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int H, M;
  cin >> H >> M;
  for(int i=H;i<25;i++){
    for(int j=0;j<60;j++){
      int lu, ld, ru, rd;
      lu = i/10;
      ld = i%10;
      ru = j/10;
      rd = j%10;
      if(60*i+j>=60*H+M&&10*lu+ru<24&&10*ld+rd<60){
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  }
  cout << 0 << ' ' << 0 << endl;
}