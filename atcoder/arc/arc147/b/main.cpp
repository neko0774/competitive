#include<bits/stdc++.h>
using namespace std;
void show(vector<int> &A){
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
  vector<pair<char, int>> ans;
  vector<int> f, b;
  for(int i=0;i<N;i++){
    if(i%2==0) f.push_back(P[i]);
    else b.push_back(P[i]);
  }


  for(int i=0;i<f.size();i++){
    for(int j=0;j<f.size()-1;j++){
      if(f[j]%2!=f[j+1]%2&&f[j]%2==1){
        swap(f[j], f[j+1]);
        ans.push_back(make_pair('B', 2*j+1));
      }
    }
  }

  for(int i=0;i<b.size();i++){
    for(int j=0;j<b.size()-1;j++){
      if(b[j]%2!=b[j+1]%2&&b[j]%2==0){
        swap(b[j], b[j+1]);
        ans.push_back(make_pair('B', 2*j+2));
      }
    }
  }

  for(int i=0;i<f.size();i+=1){
    if(f[i]%2==0){
      swap(f[i], b[i]);
      ans.push_back(make_pair('A', i*2+1));
    }
  }
  
  for(int i=0;i<f.size();i++){
    for(int j=0;j<f.size()-1;j++){
      if(f[j]>f[j+1]){
        swap(f[j], f[j+1]);
        ans.push_back(make_pair('B', j*2+1));
      }
    }
  }
  for(int i=0;i<b.size();i++){
    for(int j=0;j<b.size()-1;j++){
      if(b[j]>b[j+1]){
        swap(b[j], b[j+1]);
        ans.push_back(make_pair('B', j*2+2));
      }
    }
  }
  if(ans.size()>1e5){b[500]=2;}
  cout << ans.size() << endl;
  for(auto a: ans){cout << a.first << ' ' << a.second << endl;}
}