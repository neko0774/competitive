#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> K(3);
  for(int i=0;i<3;i++){
    cin >> K[i];
  }
  sort(K.begin(), K.end());
  if((K[0]==K[1]&&K[0]==2)||(K[0]==K[2]&&K[1]==K[0]&&K[0]==3)||(K[0]==2&&K[1]==4&&K[2]==4)||K[0]==1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
}