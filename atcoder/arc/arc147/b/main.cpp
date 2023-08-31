#include <bits/stdc++.h>
using namespace std;
vector<pair<char, int>> ans;
void sorting(vector<int> &A, int add){
  int N = A.size();
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(A[i]>A[j]){
        swap(A[i], A[j]);
        ans.push_back(make_pair('B', i*2+add+1));
        }
    }
  }
}

void collect(vector<int> &A, int add){
  int N = A.size();
  for(int i=1;i<N;i++){
    for(int j=i;j>0;j--){
      if(A[j-1]%2==add)continue;
      swap(A[j-1], A[j]);
      ans.push_back(make_pair('B', (j-1)*2+1+add));
    }
    
  }
}

void show(vector<int> A){
  for(auto a: A) cout << a << ' ';
  cout << endl;
}

int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  vector<int> f, s;
  for(int i=0;i<N;i++){
    if(i%2==0) f.push_back(P[i]);
    else s.push_back(P[i]);
  }
  
  collect(f, 0);
  collect(s, 1);
  //show(f);
  //show(s);
  //f should be 1 in mod 2
  // s would be 0
  for(int i=0;i<N-1;i++){
    if(i%2==0){
      if(f[i/2]%2==0){
        swap(f[i/2], s[i/2]);
        ans.push_back(make_pair('A', i+1));
      }
    }else{
      if(s[i/2]%2==1){
        swap(s[i/2], f[i/2+1]);
        ans.push_back(make_pair('A', i+1));
      }
    }
  }
  //show(f);
  //show(s);
  sorting(f, 0);
  sorting(s, 1);
  cout << ans.size() << endl;
  for(auto a: ans){
    cout << a.first << ' ' << a.second << endl;
  }
}