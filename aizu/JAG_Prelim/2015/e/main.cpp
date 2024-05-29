#include<bits/stdc++.h>
using namespace std;

bool solve(){
  int N, x, y;
  cin >> N;
  if(N==0) return 0;
  vector<int> dp(1<<N, 0);
  vector<vector<int>> dice_num(N, vector<int>(6));
  vector<string> dice_ord(N);
  vector<pair<int, int>> place(N);
  vector<unordered_set<int>> used(1<<N);
  for(int i=0;i<N;i++){
    cin >> x >> y;
    x += 1050;
    y += 1050;
    place[i] = make_pair(x, y);
    for(int j=0;j<6;j++){
      cin >> dice_num[i][j];
    }
    cin >> dice_ord[i];
    dice_ord[i].push_back('S');
  }

  auto score = [&](int S, int d) -> int{
    int ret = 0;
    auto [x, y] = place[d];
    vector<int> dice(6);
    for(int i=0;i<6;i++){
      dice[i] = dice_num[d][i];
    }
    unordered_map<int, int> count;
    for(char s: dice_ord[d]){
      ret -= count[x*3000+y];
      if(used[S].count(x*3000+y)==0){
        ret += dice[4];
        count[x*3000+y] = dice[4];
      }
      used[S|(1<<d)].insert(x*3000+y);
      if(s=='R'){
        dice = {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]};
        x++;
      }else if(s=='L'){
        dice = {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]};
        x--;
      }else if(s=='B'){
        dice = {dice[0], dice[1], dice[4], dice[5], dice[3], dice[2]};
        y++;
      }else{
        dice = {dice[0], dice[1], dice[5], dice[4], dice[2], dice[3]};
        y--;
      }
    }
    return ret;
  };

  for(int i=0;i<(1<<N);i++){
    for(int j=0;j<N;j++){
      if(!(i&(1<<j))){
        for(auto x: used[i]){
          used[i|(1<<j)].insert(x);
        }
        dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i]+score(i, j));
      }
    }
  }
  cout << dp[(1<<N)-1] << endl;
  return 1;
}

int main(){
  while(solve());
}