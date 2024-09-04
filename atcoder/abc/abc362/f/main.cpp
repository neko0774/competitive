#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string &T, vector<vector<int>> &nxt){
  vector<ll> dp(N + 1);
}

int main(){
  string S;
  int Q;
  cin >> S;
  cin >> Q;
  string T;
  int N = S.size();
  vector<vector<int>> nxt(N + 1, vector<int>(26, N));
  for(int i= N - 1;i >= 0;i--){
    for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
    nxt[i][S[i] - 'a'] = i;
  }
  for(int i=0;i<Q;i++){
    cin >> T;

  }
}