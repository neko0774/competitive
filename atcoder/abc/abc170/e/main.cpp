#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N, Q; cin >> N >> Q;
  vector<multiset<int>> scores(N);
  unordered_map<int, pair<int, int>> school;
  int A, B;
  for(int i=0;i<N;i++){
    cin >> A >> B;
    B--;
    scores[B].insert(A);
    school[i] = make_pair(B, A);
  }
  multiset<int> ans;
  for(int i=0;i<N;i++){
    if(scores[i].size()>0) ans.insert(*scores[i].rbegin());
  }
  int C, D;
  int f2, f1;
  for(int i=0;i<Q;i++){
    cin >> C >> D;
    D--;
    bool ok = false;
    f1 = *scores[school[C].first].rbegin();
    if(scores[D].size()>0){
      f2 = *scores[D].rbegin();
      ok = true;
    }
    ans.erase(ans.find(f1));
    if(ok) ans.erase(ans.find(f2));
    scores[school[C].first].erase(scores[school[C].first].find(f1));
    scores[D].insert(f1);
    school[C].first = D;
    cout << *ans.rbegin() << endl;
  }
  
}