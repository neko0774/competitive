#include <bits/stdc++.h>
using namespace std;

int sqnum(int x){
    if (x<0)return -1;
    for (int i=0; i*i<=x+3; i++){
        if (i*i==x)return i;
    }
    return -1;
}


int main(){
    int S, P;
    cin >> S >> P;
    int n = sqnum(S*S-4*P);
    //cout << sqnum(0) << endl;
    if (n>=0 && (S+n)%2==0){cout << "Yes" << '\n';}
    else{cout << "No" << '\n';}
}