#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int N;
  cin >> N;
  if(N==0) return false;
  map<char, int> count;
  count['n'] = 0;
  for(int i=0;i<N;i++){
    char cur;
    cin >> cur;
    count[cur]++;
    auto it = count.rbegin();
    char a = it->first;
    int top = 
    it++;
    auto head = *(++count.rbegin());
    cout << head.first << ' ' << head.second << ' ' << nxt.first << ' ' << nxt.second << endl;
    if(head.second>nxt.second+N-i-1){
      cout << head.first << ' ' << i+1 << endl;
      return true;
    }
  }
  cout << "TIE" << endl;
  return true;
}

int main(){
  while(solve()){}
}