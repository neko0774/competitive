#include<bits/stdc++.h>
using namespace std;

// unordered_map<int, int> next;

// vector<pair<int, int>> cnt;
// //i kome no value
// //<a, 0> -> Ai >= a
// //<a, 1> -> Ai <= a
// //<a, 2> -> Ai == a

// //
// void dfs(string &S, int &i, int target, int c){
//   if(S[i]!='('||S[i]!=')'){
//     //一文字
//     //条件の合わせpart


//     return;
//   }
//   int buffer = next[i];
//   if(S[i]=='>'){
//     //todo
//   }else{

//   }

//   return;
// }

// void solve(){
//   int N;cin >> N;
//   vector<int> let(N);
//   string S, T;
//   for(int i=0;i<N;i++){
//     cin >> let[i];
//   }
//   cin >> S >> T;


//   for(int i=0;i<(1<<N);i++){
//     for(int j=0;j<N;j++){
      
//     }
//   }
// }

bool is_end = false;

struct tree {
  string s;
  vector<int> left, right, par;
  tree(string s) : s(s) {
    
  }
};

void solve() {
  int n;
  string a, S, T;
  cin >> n >> a >> S >> T;
  long long ans = 0;
  vector<tuple<string, string, long long>> dp(1 << n);
  dp[0] = make_tuple(S, T, 1);
  for(int i = 0; i < 1 << n; i++) {
    auto [p, q, cnt] = dp[i];
    for(int j = 0; j < n; j++) {
      if((i >> j) % 2 == 1) continue;
    }
  }
}

int main(){
  while(!is_end) { solve(); }
}