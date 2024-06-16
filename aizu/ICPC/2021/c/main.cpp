#include<bits/stdc++.h>
using namespace std;

int vertex_num = 0;
int cur = 0;
vector<int> G[1<<20];
struct node{
  //s==0 -> num
  //s==1 -> op
  int s;
  int num;
  string op;
};
vector<node> conv(1<<20);

int parse_num(string &S){
  int ret = 0;
  while('0'<=S[cur]&&S[cur]<='9'){
    ret *= 10;
    ret += S[cur]-'0';
    cur++;
  }
  return ret;
}


void parse_non_root(string &S, int par){
  if('0'<=S[cur]&&S[cur<='9']){
    int n = parse_num(S);
    G[par].push_back(vertex_num);
    G[vertex_num].push_back(par);
    conv[vertex_num].s=0;
    conv[vertex_num].num = n;
    vertex_num++;
  }else{
    //( -> skip
    int cur_par = vertex_num;
    vertex_num++;
    G[par].push_back(cur_par);
    G[cur_par].push_back(cur_par);
    cur++;
    parse_non_root(S, cur_par);
    conv[vertex_num].s=1;
    conv[vertex_num].op=S[cur];
    cur++;
    //op skip
    parse_non_root(S, cur_par);
    cur++;
  }
}

void parse(string &S){
  int par = 0;
  conv[par].s = 1;
  vertex_num++;
  parse_non_root(S, par);
  conv[par].op = S[cur];
  cur++;
  parse_non_root(S, par);
  cur++;
  parse_non_root(S, par);
}


int calc(vector<pair<int, int>> &dp, int x){
  if(conv[x].s==0) return conv[x].num;
  int max_memo = 0;
  int min_memo = 0;
  vector<pair<int, int>> val;
  for(auto nx: G[x]){
    if(dp[nx].first==-1) calc(dp, nx);
    val.push_back(dp[nx]);
  }
  if(dp[nx].)
}



bool solve() {
  string S;
  cin >> S;
  if(S == "-1") {
    return 0;
  }
  for(int i=0;i<1<<20;i++){
    G[i].clear();
  }
  conv.clear();
  vertex_num = 0;
  cur = 0;
  parse(S);
  const int N = vertex_num;
  int ans = 0;
  vector<pair<int, int>> dp(N, {-1, -1});
  //first -> max
  //second -> min
  for(int i=0;i<N;i++){
    if(dp[i].first==-1){
    ans = max(ans, calc(dp, i));
    }
  }

  return 1;
}


int main() {
  while(solve()) {}
}