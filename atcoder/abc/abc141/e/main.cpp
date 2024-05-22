#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct rollinghash{
  long long MOD, B;
  vector<T>  hash, power;
  rollinghash(string &s, long long base, long long mod){
    vector<T> S;
    MOD = (long long)mod;
    B = (long long)base;
    for(char ss: s) S.emplace_back(ss);
    int N = S.size();
    hash.assign(N+1, 0);
    power.assign(N+1, 0);
    for(int i=0;i<N;i++){
      hash[i+1] = ((long long)hash[i]*B+S[i])%MOD;
      power[i+1] = ((long long)power[i]*B)%MOD;
    }
  }

  T get(int l, int r){
    T ret = (long long)hash[r]+MOD-(long long)hash[l]*power[r-1]%MOD;
    if(ret>=MOD)ret-=MOD;
    return ret;
  }

  int LCP(rollinghash<T> &str2, int l1, int r1, int l2, int r2){
    int len = min(r1-l1, r2-l2);
    int ng = len+1, ok = 0;
    while(ng-ok>1){
      int mid = (ok+ng)/2;
      if(get(l1, l1+mid)==str2.get(l2, l2+mid)) ok = mid;
      else ng = mid;
    }
    return ok;
  }
};
const long long mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  rollinghash<long long> rh(S, 200, mod);
  int ok = 0, ng = N/2+1;
  while(abs(ok-ng)>1){
    int mid = (ok+ng)/2;
    unordered_set<long long> hashs;
    for(int i=0;i<N-mid;i++){
      cout << i << ' ' << mid << ' ' << rh.get(i, i+mid) << endl;
      if(hashs.count(rh.get(i, i+mid))){
        ok = mid;
        break;
      }
      hashs.emplace(rh.get(i, i+mid));
    }
    if(ok!=mid) ng = mid;
  }
  cout << ok << endl;
}