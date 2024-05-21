#include<bits/stdc++.h>
using namespace std;

int count(vector<int> ary, vector<int> A){
  int sz = ary.size();
  int ret =0;
  if(ary[0]+A[0]>A[1]+ary[1])ret++;
  if(ary[sz-1]+A[sz-1]>A[sz-2]+ary[sz-2])ret++;
  for(int i=1;i<sz-1;i++){
    if(ary[i]+A[i]>ary[i-1]+A[i-1]&&ary[i]+A[i]>ary[i+1]+A[i+1]) ret++;
  }
  return ret;
}

vector<int> calc(vector<int> A, int N, int b){
  vector<int> B(N, 0);
  vector<pair<int, int>> front, back;
  for(int i=0;i<N;i++){
    if(i%2==b){
      front.push_back(make_pair(A[i], i));
    }else{
      back.push_back(make_pair(A[i], i));
    }
  }
  sort(front.begin(), front.end());
  sort(back.begin(), back.end());
  int V = N;
  for(auto [v, i]: front){
    B[i] += V;
    V--;
  }
  for(auto [v, i]: back){
    B[i] += V;
    V--;
  }
  return B;
}

void solve(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  vector<int> B1, B2;
  B1 = calc(A, N, 1);
  B2 = calc(A, N, 0);
  if(count(B1, A)>count(B2, A)){
    for(auto b: B1) cout << b << ' ';
  }else{
    for(auto b: B2) cout << b << ' ';
  }
  cout << endl;
}

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    solve();
  }  
}