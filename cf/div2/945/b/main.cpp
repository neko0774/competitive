#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<int> cnt(21, 0);
  int ok = N, ng = 0;
  while(ok-ng>1){
    int mid = (ok+ng)/2;
    bool flag = true;
    cnt = vector<int>(21, 0);
    for(int j=0;j<mid;j++){
      for(int i=0;i<21;i++){
        if((A[j]>>i)&1){
          cnt[i]++;
        }
      }
    }
    for(int k=mid;k<N;k++){
      for(int i=0;i<21;i++){
        if((A[k]>>i)&1){
          if(cnt[i]==0){
          flag = false;
          break;
          }else{
            cnt[i]++;
          }
        }
        if((A[k-mid]>>i)&1){
          if(cnt[i]==1){
            flag = false;
            break;
          }else{
            cnt[i]--;
          }
        }
      }
    }
    if(flag) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    solve();
  } 
}