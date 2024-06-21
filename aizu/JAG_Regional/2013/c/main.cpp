#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;


ll expr(string &S);
ll term(string &S);
void sp(string &S);
ll number(string &S);

int cur;
ll expr(string &S){
  cout << "expr" << ' ' << S[cur] << ' ' << cur << endl;
  if(S[cur]=='S'||('0'<=S[cur]&&S[cur]<='9')){
    return term(S);
  }else{
    ll s = expr(S);
    sp(S);
    //>>
    cur+=2;
    sp(S);
    ll t = term(S);
    return s>>t;
  }
}

ll term(string &S){
  cout << "term" << endl;
  if('0'<=S[cur]&&S[cur]<='9') return number(S);
  else{
    //S
    cur++;
    sp(S);
    //<
    cur++;
    sp(S);
    ll x = expr(S);
    sp(S);
    //>
    cur++;
    return x%mod*x%mod;
  }
}

void sp(string &S){
  cout << "sp" << endl;
  while(S[cur]==' ')cur++;
}

ll number(string &S){
  cout << "number" << endl;
  ll ret = 0;
  while('0'<=S[cur]&&S[cur]<='9'){
    ret *= 10;
    ret += S[cur]-'0';
  }
  return ret;
}


string input(){
  string S;
  getline(cin, S);
  return S;
}


bool is_end = false;
void solve(){
  string S = input();
  if(S=="#"){
    is_end = true;
    return;
  }
  cur = 0;
  cout << S[cur] << endl;
  cout << expr(S) << endl;
  return;
}

int main(){
  while(!is_end){
    solve();
  }
  return 0;
}