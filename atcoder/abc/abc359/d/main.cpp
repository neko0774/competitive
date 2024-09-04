#include<bits/stdc++.h>
using namespace std;
#include<atcoder/modint>
using mint = atcoder::modint998244353;
bool is_parindrome(string S){
  int K = S.size();
  for(int i=0;i<K/2;i++){
    if(S[i]!=S[K-i-1]) return false;
  }
  return true;
}

int main(){
  int N, K;
  cin >> N >> K;
  string S;
  unordered_map<char, string> to_add = {{'A', "A"}, {'B',"B"}, {'?',"AB"}};
  cin >> S;
  unordered_map<string, mint> cur;
  cur[string(K-1, 'C')] = 1;
  for(char s: S){
    unordered_map<string, mint> nxt;
    for(auto [curs, cnt]:cur){
      for(auto c: to_add[s]){
        if(!is_parindrome(curs+c)){
          nxt[curs.substr(1)+c] += cnt;
        }
      }
    }
    swap(nxt, cur);
  }
  mint ans = 0;
  for(auto [a, v]: cur){
    ans += v;
  }
  cout << ans.val() << endl;
}