#include<iostream>
#include<iomanip>
using namespace std;


int main(){
  long long n,m,d;
  cin >> n,m,d;
  long double s = (n-d)*(m-1);
  long double div = n;
  cout << setprecision(10) << s/div << endl;
}