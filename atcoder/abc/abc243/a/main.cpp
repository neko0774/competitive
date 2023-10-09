#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int V, A, B, C;
  cin >> V >> A >> B >> C;
  while(true){
  if(V-A<0){
    cout << "F" << endl;
    return 0;
  }
  V -= A;
  if(V-B<0){
    cout << "M" << endl;
    return 0;
  }
  V -= B;
  if(V-C<0){
    cout <<"T" << endl;
    return 0;
  }
  V -= C;
  }
}