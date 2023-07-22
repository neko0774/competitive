#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  int A[H+2][W+2];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A[i][j];
    }
  } 
  vector<int> WW(W);
  vector<int> HH(H);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      WW[j] += A[i][j];
      HH[i] += A[i][j];
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << WW[j]+HH[i]-A[i][j] << ' ';
    }
    cout << endl;
  }

}