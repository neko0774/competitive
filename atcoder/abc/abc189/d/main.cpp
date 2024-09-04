#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  pair<long, long> cnt = {1, 1};
  for(int i=0;i<N;i++){
    cin >> S;
    if(S == "OR"){
      cnt = {cnt.first * 2 + cnt.second, cnt.second};
    }else{
      cnt = {cnt.first, cnt.second * 2 + cnt.first};
    }
  }
  cout << cnt.first << endl;
}