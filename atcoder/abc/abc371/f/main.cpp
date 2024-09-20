#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  cin >> N;
  vector<int> X(N);
  map<int, int> T, pos;
  for(int i = 0; i < N; i++){
    cin >> X[i];
    X[i] -= i;
    if(T[X[i]] == 0)T[X[i]] = i;
  }
  for(auto x: T){
    pos[x.second] = x.first;
  }
  int Q;
  cin >> Q;
  int ans = 0;
  for(int i = 0;i < Q; i++){
    cin >> t >> g;
    t--;
    auto cur = pos.lower_bound(t);
    int cur_pos = cur->second;
    int head = cur->first;
    if(cur == g) continue;
    
    if(cur > g){
      //to left
      int nxt_head = -1;
      if(T.lower_bound(g)->second == head){
        nxt_head = head;
      }else{
        nxt_head = T.lower_bound(g)->second;
      }
      while(T.lower_bound(g)->second != head){
        auto to_del = T.lower_bound(g);
        T.erase(to_del->first);
        pos.erase(to_del->second);
        ans += 
      }
      T.emplace({g, nxt_head});
      pos.emplace({nxt_head, g});
    }else{
      //to right

    }
  }

  
}