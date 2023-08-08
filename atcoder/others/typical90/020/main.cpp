#include <iostream>
using namespace std;

#define ll long long

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll e = 1;
  for(int i=0;i<b;i++){
    e *= c;
    if(e>a){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}