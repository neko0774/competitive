#include <bits/stdc++.h>
using namespace std;

double calc(double x, double p){
  return x+p/pow(2, x/1.5);
}


int main(){
  double P;
  cin >> P;
  double l=0, r=100;
  int cnt = 1000;
  while(--cnt){
    double l1 = (l*2+r)/3;
    double r1 = (l+r*2)/3;

    if (calc(l1, P)>calc(r1, P)) l = l1;
    else r = r1;
  }
  cout << setprecision(15) << calc(r, P) << endl;

}