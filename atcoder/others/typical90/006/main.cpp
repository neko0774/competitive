#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e6;

template<typename T>
void show(vector<vector<T>> A){
  for(auto a: A){
    for(auto aa: a) cout << aa << ' ';
    cout << endl;
  }
}

vector<vector<ll>> nxt_let(string S){
  int N = S.length();
  vector<vector<ll>> ret(N+1, vector<ll>(26, -1));
  for(int i=N-1;i>=0;i--){
    for(int j=0;j<26;j++){
      if(S[i]-'a'==j)ret[i][j] = (ll)i;
      else ret[i][j] = ret[i+1][j];
    }
  }
  return ret;
}

int main(){
  ll N, K;
  string S;
  cin >> N >> K;
  cin >> S;
  auto nxt = nxt_let(S);
  string ans="";
  //show(nxt);
  int i = 0;
  while(i<N){
    if(ans.length()>=K) break;
    for(int j=0;j<26;j++){
      if(nxt[i][j]!=-1&&K-ans.length()<=N-nxt[i][j]){
        ans += (char)(j+97);
        i=nxt[i][j]+1;
        break;
      }
    }
  }
  cout << ans << endl;
}