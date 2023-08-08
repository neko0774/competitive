#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
const int INF = 1<<30;
int op(int a, int b){return min(a, b);}
int e(){return INF;}


bool compare(vector<int> &A, vector<int> &B){
  if(A[0]==B[0]){
    if(A[1]==B[1]) return A[2]>B[2];
    return A[1]>B[1];
  }
  return A[0]<B[0];
}

int main(){
  int N;
  cin >> N;
  unordered_map<int, int> conv;
  unordered_set<int> find;
  vector<vector<int>> box;
  for(int i=0;i<N;i++){
    int h, w, d;
    cin >> h >> w >> d;
    vector<int> vec = {h, w, d};
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    find.insert(vec[1]);
    box.push_back(vec);
  }
  vector<int> vv;
  for(auto x: find){
    vv.push_back(x);
  }
  int i=0;
  sort(vv.begin(), vv.end());
  for(auto v:vv){
    conv[v] = i;
    i++;
  }
  for(auto &x: box){
    x[1] = conv[x[1]];
  }
  sort(box.begin(), box.end(), compare);
  atcoder::segtree<int, op, e> seg(N);
  for(auto x: box){
    if(seg.prod(0, x[1])<x[2]){
      cout << "Yes\n";
      return 0;
    }
    if(seg.get(x[1])>x[2]) seg.set(x[1], x[2]);
  }
  cout << "No\n";
}