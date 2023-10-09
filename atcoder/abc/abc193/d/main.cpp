#include <bits/stdc++.h>
using namespace std;
#define ll long long


int score(string S, int s){
  unordered_map<int, int> cnt;
  for(auto ss: S) cnt[ss-'0']++;
  cnt[s]++;
  int ret = 0;
  for(int i=1;i<10;i++){
    int c = 1;
    while(cnt[i]--) c*=10;
    ret += i*c;
  }
  return ret;
}



long double prob(string S, string T, int i, int j, int K){
  vector<int> seen(9);
  for(auto s: S) seen[s-'1']++;
  for(auto s: T) seen[s-'1']++;
  long double ret = (long double)(K-seen[i-1])/(long double)(9*K-8);
  seen[i-1]++;
  ret = ret*((long double)K-seen[j-1])/((long double)(9*K-9));
  return ret;
}

int main(){
  int K;
  cin >> K;
  string S;
  string T;
  cin >> S;
  cin >> T;
  S.pop_back();
  T.pop_back();
  long double ans=0;
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      if(score(S, i)>score(T, j)){
        ans += prob(S, T, i, j, K);
      }
    }
  }
  cout << setprecision(10) << ans << endl;
}