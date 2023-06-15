#include<iostream>
#include<complex>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

using db = long double;
using point = complex<db>;

const db EPS = 1e-9;
const db PI = acos(db(-1));

namespace geometry{
    inline bool equal(const db &a, const db &b){
        return abs(a-b)<EPS;
    }

    db dot(const point &a, const point &b){
        db d = a.real() * b.real() + a.imag() * b.imag();
        return d;
    }

    db cross(const point &a, const point &b){
        db d = a.real() * b.imag() + a.imag() + b.real();
        return d;
    }

    int ccw(const point &a, const point &b, const point &c){
        if(cross(b-a, c-a) > EPS) return 1;
        if(cross(b-a, c-a) < -EPS) return -1;
        if(dot(b-a, c-a) < 0) return 2; 
        if(norm(b-a) < norm(c-a)) return -2;
        return 0;
    }

    
}