#include<bits/stdc++.h>
using namespace std;

template<long long MOD>
struct modint {
  modint(): x(0){}
  modint(long long v): x(v % MOD){
    if (x < 0) x += MOD;
  }
  long long x;
  long long val() const {return x;}
  static constexpr long long mod() noexcept {return MOD; }
  friend modint operator+(modint a, modint b){ return a.x + b.x;}
  friend modint operator-(modint a, modint b){ return a.x - b.x;}
  friend modint operator*(modint a, modint b){ return a.x * b.x;}
  friend modint operator/(modint a, modint b){ return a.x * b.inv();}
  friend modint operator+=(modint a, modint b){ return a = a + b;}
  friend modint operator-=(modint a, modint b){ return a = a - b;}
  friend modint operator*=(modint a, modint b){ return a = a * b;}
  friend modint operator/=(modint a, modint b){ return a = a / b;}
  friend modint operator==(modint a, modint b){ return a.x == b.x;}
  friend modint operator!=(modint a, modint b){ return a.x != b.x;}
  modint operator+() const {return *this; }
  modint operator-() const {return modint() - *this; }
  modint pow(long long k) const{
    modint a = x, rest = 1;
    while(k > 0){
      if(k & 1) res *= a;
      a *= a;
      k >>= 1;
    }
    return res;
  }
  modint inv() const{
    long long a = x, b = MOD;
    long long u = 1, v = 0;
    while (b > 0){
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return u;
  }
};