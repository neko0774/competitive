#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  unordered_set<string> seen;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    if(seen.count(s)==0){
      cout << i+1 << '\n';
      seen.insert(s);
    }
  }
}