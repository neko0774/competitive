#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int K, N;
  cin >> N >> K;
  unordered_map<int, int> cnt;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int l = 0;
  int ans = 0;
  for(int r=0;r<N;r++){
    cnt[A[r]]++;
    while(l<r&&cnt.size()>K){
      cnt[A[l]]--;
      if(cnt[A[l]]==0) cnt.erase(A[l]);
      l++;
    }
    ans = max(r-l+1, ans);
  }
  cout << ans << endl;
}