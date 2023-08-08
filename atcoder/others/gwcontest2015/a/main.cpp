#include <bits/stdc++.h>
using namespace std;
void show(set<int> A){
  for(auto x: A) cout << x << ' ';
  cout << endl;
}

int main(){
  vector<int> score = {25,39,51,76,163,111,128,133,138};
  //vector<int> score = {100, 120};
  set<int> ans;
  ans.insert(0);
  for (auto nx: score){
    set<int> nxtscore;
    for(auto x: ans){
      nxtscore.insert(x+nx);
    } 
    for(auto x: nxtscore) ans.insert(x);
  }
  set<int> A;
  for(auto xx: ans){
    A.insert(xx);
    A.insert(xx+58);
    A.insert(xx+136);
  }
  for(auto a: A) cout << a << endl;
}