#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int l = 0;
  ll ans = 0;
  int cntg = 0;
  int cntb = 0;
  for(int r=0;r<N;r++){
    if(S[r]=='o') cntg++;
    else cntb++;
    while(r>l&&!(cntg==0||cntb==0)){
      if(S[l]=='o') cntg--;
      else cntb--;
      l++;
    }
    ans += (ll)l;
  }
  cout << ans << endl;
}