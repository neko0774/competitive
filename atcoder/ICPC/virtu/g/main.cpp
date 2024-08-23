#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll ans, N;
int cur;
string S;
ll parse();
void calc(int ll, int rr, vector<ll> &B, vector<unordered_map<ll, int>> &count);



pair<ll, ll> addition(int l, unordered_map<ll, int> &cnt, vector<ll> &B, vector<unordered_map<ll, int>> &count){
  int s = cur;
  ll ret = 1;
  bool ok = true;
  ll mult = 1;
  deque<ll> q;
  while(S[cur] != '+'){
    ll v;
    if(S[cur] == '('){
      cur++;
      v = parse();
      cur++;
    }else{
      v = S[cur] - '0';
      cur++;
      // '*' + number
    }
    if(S[cur] == '*') cur++;

    ret *= v;
    q.push_back(v);
    mult *= v;
    if(mult==N) ans++;
    while(mult > N){
      mult /= q.front();
      q.pop_front();
    }
    cnt[ret]++;
    if(ret > N){
      //if the addition is greater than n
      count.push_back(cnt);
      calc(l, s, B, count);
      ok = false;
      ret = 0;
    }
  }
  //wakou < n 
  if(ok) return make_pair(ret, ok);
  count.clear();
  cnt.clear();
  int v = 1;
  for(auto x: q){
    v *= x;
    cnt[v]++;
  }
  count.push_back(cnt);
  return make_pair(v, ok);
}

void calc(int ls, int rs, vector<ll> &B, vector<unordered_map<ll, int>> &count){
  //B = {0, block_0, block_1, ... }
  int block = 0;
  ll c_val = 1;
  for(int l = ls; ls < rs; l+2){
    c_val *= S[l];
    
  }
}

ll prase(){
  unordered_map<ll, int> cnt;
  vector<ll> B = {0};
  vector<unordered_map<ll, int>> count;
  int l = cur;
  while(true){
    cnt.clear();
    auto [v, ok] = addition(l, cnt, B, count);
    if(!ok){
      //v > n
      l = cur;
      B = {0, v};
    }else{
      B.push_back(*B.rbegin() + v);
      count.push_back(cnt);
    }
  }
  calc(l, cur, B, count);
}

bool solve(){
  cin >> N;
  if (N == 0) return false;
  cin >> S;
  ans = 0;
  cur = 0;
  int v = prase();
  if(v == N) ans++;
  cout << ans << endl;
  return true;
}

int main(){
  while(solve()){}
}