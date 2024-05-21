#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  unordered_map<int, int> ex;
  for(int i=0;i<M;i++){
    cin >> A[i];
    if(A[i]==1||A[i]==N){
      cout << -1 << endl;
      return 0;
    }
    ex[A[i]]++;
  }
  sort(A.begin(), A.end());
  set<int> use;
  for(int i=0;i<N;i++){
    use.insert(i);
  }
  vector<int> ans;
  int ma = -1;
  bool flag = true;
  bool ok;
  for(int i=0;i<N;i++){
    int v = *use.begin();
    ok = true;
    if(max(ma, v)==i&&ex[i+1]==1){
      ok = false;
    }

    if(!ok){
      if(use.upper_bound(v)!=use.end()){
        v = *use.upper_bound(v);
      }else{
        flag = false;
      }
    }
    ans.push_back(v);
    use.erase(v);
    ma = max(ma, v);
  }
  if(flag) for(auto a: ans) cout << a+1 << ' ' ;
  else cout << -1 << endl;
}