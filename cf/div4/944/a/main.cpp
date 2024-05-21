#include<bits/stdc++.h>
using namespace std;


int main(){
  int T;
  cin >> T;
  int x, y;
  for(int i=0;i<T;i++){
    cin >> x >> y;
    cout << min(x, y) << ' ' << max(x, y) << endl;
  } 
}