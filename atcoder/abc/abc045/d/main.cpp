#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;



int main(){
  long long H, W, N;
  cin >> H >> W >> N;
  unordered_set<long long> place;
  vector<pair<long long, long long>> colour;
  vector<pair<int, int>> dxy;
  for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){
      dxy.push_back(make_pair(i, j));
    }
  }
  for(int i=0;i<N;i++){
    long long a, b;//H, W
    cin >> a >> b;
    a--;
    b--;
    place.insert(a*W+b);
    colour.push_back(make_pair(a, b));
  }
  unordered_map<int, unordered_set<long long>> ans;
  long long c = 0;
  for(auto npair: colour){
    long long a = npair.first;
    long long b = npair.second;
    for(auto ndxy: dxy){
      bool flag = true;
      long long na = a+ndxy.first;
      long long nb = b+ndxy.second;
      int cnt = 0;
      for(auto nnxy: dxy){
        long long nna = na+nnxy.first;
        long long nnb = nb+nnxy.second;
        if(place.count(nna*W+nnb)>=1)cnt++;
        if(nna<0||nna>=H||nnb<0||nnb>=W) flag = false;
      }
      if(flag) ans[cnt].insert(na*W+nb);
      //if(flag) cout << na << ' ' << nb << ' ' << na*W+nb << ' ' << cnt << endl;
    }
  }
  //for(auto x: ans){
  //  cout << x.first << endl;
  //  for(auto nx: x.second) cout << nx << ' ';
  //  cout << endl;
  //}
  for(int i=1;i<10;i++)c+= ans[i].size();
  cout << (H-2)*(W-2)-c << endl;
  for(int i=1;i<10;i++)cout << ans[i].size() << endl;
}