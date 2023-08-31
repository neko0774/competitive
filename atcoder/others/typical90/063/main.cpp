#include<bits/stdc++.h>
using namespace std;
#define ll long long

void show(unordered_map<ll, ll> a){
  for(auto nx: a)cout << nx.first << ' ' << nx.second << endl;
}



int main(){
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> P(H, vector<ll>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >>P[i][j];
    }
  }
  ll ans = 0;
  for(int i=0;i<(1<<H);i++){
    unordered_map<ll, ll> cnt;
    for(int x=0;x<W;x++){
      unordered_map<ll, ll> memo;
      bool flag = true;
      ll ls=-1;
      for(int y=0;y<H;y++){
        if((i>>y)&1){
          if(ls==-1) ls = P[y][x];
          else if(ls!=P[y][x]){
            flag = false;
            break;
          }
          memo[P[y][x]]++;
        }else if(!flag) break;
      }
      if(flag){
        for(auto nx: memo){
          cnt[nx.first] += nx.second;
        }
      }
    }
    for(auto nx: cnt){ans= max(ans, nx.second);
    }
  }
  cout << ans << endl;
}