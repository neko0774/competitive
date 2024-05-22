#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> W(N);
  for(int i=0;i<N;i++){
    cin >> W[i];
  }
  vector<int> child, adult;
  vector<int> check;
  for(int i=0;i<N;i++){
    check.push_back(W[i]);
    check.push_back(W[i]+1);
    if(S[i]=='1'){
      //adult
      adult.push_back(W[i]);
    }else{
      child.push_back(W[i]);
    }
  }
  sort(child.begin(), child.end());
  sort(adult.begin(), adult.end());
  int ans = 0;
  int nn = adult.size();
  for(auto x: check){
    int l = lower_bound(child.begin(), child.end(), x)-child.begin();
    int r = nn - (lower_bound(adult.begin(), adult.end(), x)-adult.begin());
    ans = max(ans, l+r);
  }
  cout << ans << endl;
}