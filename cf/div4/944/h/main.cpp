#include<bits/stdc++.h>
using namespace std;

#define ll long long

//scc
struct SCC{
  vector<vector<int>> G, rG; 
  int N;
  struct SCC(int _N):N(_N){
    G = vector<vector<int>>(N);
    rG = vector<vector<int>>(N);
  }
  
  void add_edge(int from, int to){
    assert(0<=from&&from<N);
    assert(0<=to&&to<N);
    G[from].push_back(to);
    rG[to].push_back(from);   
  }


  vector<vector<int>> deconstruct(){
    vector<bool> seen1(N), seen2(N),
    vector<int> ord();
    auto dfs = [&](auto dfs, int x, int par){
      seen1[x] = 1;
      for(auto &nx:G[x]){
        if(!seen1[nx]) dfs(nx, x);
      }
      ord.push_back(x);
    };

    auto rdfs = [&](auto rdfs, int x, int par){
      seen2[x] = 1;
      for(auto &nx:rG[x]){
        if(!seen2[nx]) rdfs(nx, x);
      }
      ord.push_back(x);
    };
    reverse(ord.begin(), ord.end());
    vector<vector<int>> ans;
    for(auto x: order){
      if(!seen2[x]){
        vector<int> groups;
        rdfs(x, -1, x);
        ans.push_back(groups);
      }
    }
    return ans;
  }
};



//2-sat
struct two_sat{
  SCC graph;
  vector<int> ans;
  int N;
  two_sat(int _N): N(_N), graph(2*_N), ans(_N){}

  //not = neg value
  void add(int x, bool is_x, int y, bool is_y){
    graph.add_edge(2*x+(is_x ? 0:1), 2*y+(is_y? : 1:0));
    graph.add_edge(2*y+(is_y ? 0:1), 2*x+(is_x? : 1:0));
  };


  bool is_satisfied(){
    auto id = graph.deconstruct();
    for(int i=0;i<N;i++){
      if(id[2*i+1]==id[2*i]) return false;
      ans[i] = id[2*i] < id[2*i+1];
    }
    return true;
  }

  vector<int> construct(){
    return ans;
  }
};


void solve(){
  int N;
  cin >> N;
  vector<vector<int>> G(3, vector<int>(N));
  for(int i=0;i<3;i++){
    for(int j=0;j<N;j++){
      cin >> G[i][j];
    }
  }

}


int main(){
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}