#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
void show(vector<T> A){
  for(T a: A)cout << a << ' ';
  cout << endl;
}

int match(string &str_pat, string &str_to_match){
  int idx = 0;
  for(int i=0;i<str_to_match.size();i++){
    if(idx<str_pat.size()&&str_pat[idx]==str_to_match[i]){idx++;}
  }
  return idx;
}
int match_rev(string &str_pat, string &str_to_match){
  int idx = 0;
  for(int i=str_to_match.size();i>=0;i--){
    if(idx<str_pat.size()&&str_pat[str_pat.size()-idx-1]==str_to_match[i])idx++;
  }
  return idx;
}

int main(){
  int N;cin >> N;
  string T;
  cin >> T;
  vector<string> ary(N);
  for(int i=0;i<N;i++){
    cin >> ary[i];
  }
  vector<ll> front(N), back(N);
  for(int i=0;i<N;i++){
    front[i] = match(T, ary[i]);
    back[i] = match_rev(T, ary[i]);
  }
  ll ans = 0;
  sort(front.begin(), front.end());
  for(int i=0;i<N;i++){
    ans += N-distance(front.begin(), lower_bound(front.begin(), front.end(), T.size()-back[i]));
  }
  cout << ans << endl;
}