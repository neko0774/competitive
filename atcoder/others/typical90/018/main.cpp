#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const  long double pi = 3.14159265358979;

int main(){
  long double T;
  cin >> T;
  long double L, X, Y;
  cin >> L >> X >> Y;
  int Q;
  cin >> Q;
  for(int i=0;i<Q;i++){
    long double E;
    cin >> E;
    long double ang = E/T*2*pi;
    long double YY = -L*sin(ang)/2;
    long double ZZ = L/2-L*cos(ang)/2;

    long double d = sqrt(X*X+(YY-Y)*(YY-Y));
    long double angle = atan2l(ZZ, d)*180/pi;
    cout << setprecision(15) << abs(angle) << endl;
  }
}