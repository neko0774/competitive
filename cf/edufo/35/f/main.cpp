#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(K);
  vector<int> B;
  stack<int> S;
  set<int> rem;
  for(int i=0;i<N;i++){
    rem.insert(i);
  }
  for(int i=0;i<K;i++){
    cin >> A[i];
    A[i]--;
    rem.erase(A[i]);
    if(S.size()==0||S.top()>A[i]){
      S.push(A[i]);
    }else{
      while(S.size()!=0&&S.top()<A[i]){
        B.push_back(S.top());
        S.pop();
      }
      S.push(A[i]);
    }
  }
  vector<int> res;
  while(B.size()<N){
    if(S.size()){
      while(S.size()!=0&&rem.lower_bound(S.top())==rem.end()){
        B.push_back(S.top());
        S.pop();
      }
      if(rem.size()>0){
        int v = *rem.lower_bound(S.top());
        S.push(v);
        res.push_back(v);
        rem.erase(v);
      }else{
        while(S.size()){
          B.push_back(S.top());
          S.pop();
        }
      }
    }else if(rem.size()>0){
        int v = *rem.lower_bound(S.top());
        S.push(v);
        res.push_back(v);
        rem.erase(v);
    }
  }

  for(int i=1;i<N;i++){
    if(B[i-1]<B[i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;

}