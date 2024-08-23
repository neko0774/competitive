#include<bits/stdc++.h>
using namespace std;
#define ll long long

int buffer;
vector<int> ans;
int A, B;
bool is_corner(int x, int y){
  if ((x == 0 && y == 0) || (x == 0 && y == B) || (x == A && y == 0) || (x == A && y == B))return true;
  return false;
}



void find(int x, int y, int slope, vector<vector<pair<int, int>>> &pos, vector<vector<pair<int, int>>> &neg, unordered_set<ll> &vis){
  //2 no part
  if(vis.count((ll)y * (ll)A + (ll)x) > 0 || is_corner(x, y)) return;
  vis.insert((ll)y * (ll)A + (ll)x);
  int nx, ny, nslope;
  if(y == 0){
    //3-1
    if(slope == 1){
      if(A - x == B) return;

      if(A - x < B) nx = A, ny = A - x;
      else nx = x + B, ny = B;
    }else{
      if(x == B) return;
      
      if(x < B) nx = 0, ny = x;
      else nx = x - B, ny = B;
    }
  }else if(x == 0){
    //3-2
    if(slope == 1){
      if(B - y == A) return;

      if(B - y < A) nx = B - y, ny = B;
      else nx = A, ny = y + A;
    }else{
      if(y == A) return;
      
      if(y < A) nx = y, ny = 0;
      else nx = A, ny = y - A;
    }
  }else if(y == B){
    if(slope == -1 && pos[x + B].size() > 0){
      ans.push_back(pos[x + B].begin()->second);
      return;
    }
    //3-3
    if(slope == 1){
      if(x == B) return;

      if(x < B) nx = 0, ny = B - x;
      else nx = x - B, ny = 0;
    }else{
      if(A - x == B) return;
      
      if(A - x < B) nx = A, ny = B - A + x;
      else nx = x + B, ny = 0;
    }
  }else if(x == A){
    if(slope == -1 && pos[A + y].size() > 0){
      ans.push_back(pos[A + y].rbegin()->second);
      return;
    }
    //3-3
    if(slope == 1){
      if(y == A) return;
      
      if(y < A) nx = A - y, ny = 0;
      else nx = 0, ny = y - A;
    }else{
      if(B - y == A) return;

      if(B - y < A) nx = A - B + y, ny = B;
      else nx = 0, ny = y + A;
    }
  }
  find(nx, ny, -slope, pos, neg, vis);
}

bool solve(){
  int N, X, Y;
  cin >>  A >> B >> X >> Y >> N;
  if (N == 0) return false;
  ans.clear();
  buffer = A;
  vector<vector<pair<int, int>>> coin_pos(A + B + 1, vector<pair<int, int>>()), coin_neg(A + B + 1, vector<pair<int, int>>());
  int x, y;
  //1 part
  // cout << 'L' << endl;
  for(int i=0;i<N;i++){
    cin >> x >> y;
    // cout << A + B + 1 << endl;
    // cout << x + y << endl;
    // cout << y - x + buffer << endl;
    coin_pos[x+y].emplace_back(x, i);
    coin_neg[y-x+buffer].emplace_back(x, i);
  }
  // cout << 'L' << endl;
  for(int i=0;i<A+B+1;i++){
    sort(coin_pos.begin(), coin_pos.begin());
    sort(coin_neg.begin(), coin_neg.begin());
  }
  //4 no part
  for(int i=0;i<4;i++){
    int slope;
    int nx, ny;
    bool ok = false;
    unordered_set<ll> vis;
    if(i==0){
      //I
      //migi ue
      slope = 1;
      if(B - Y + X < A) nx = B - Y + X, ny = B;
      else nx = A, ny = A + Y - X;
      //find next x and y
    }else if(i == 1){
      //II
      //migi sita
      slope = -1;
      if(Y + X < A) nx = Y + X, ny = 0;
      else nx = A, ny = Y + X - A;
    }else if(i == 2){
      //III
      //hidari ue
      slope = -1;
      if(X + Y - B > 0) nx = X + Y - B, ny = B;
      else nx = 0, ny = X + Y;
    }else if(i == 3){
      //IV
      //hidari sita
      slope = 1;
      for(auto &[x, index]: coin_neg[Y - X + buffer]){
        if(x > X){
          ans.push_back(index);
          ok = true;
          break;
        }
      }
      if(Y - X > 0) nx = 0, ny = Y - X;
      else nx = X - Y, ny = 0;
    }
    if(!ok) find(nx, ny, -slope, coin_pos, coin_neg, vis);
    cout << i << '|';
    for(auto nx: ans)cout << nx << ' ';
    cout << endl;
  }
  if(ans.size()==0) cout << "No" << endl;
  else{
    unordered_set<int> seen;
    sort(ans.begin(), ans.end());
    for(int a: ans){
      if(seen.count(a) > 0) continue;
      seen.insert(a);
      cout << a + 1 << ' ';
    }
    cout << endl;
  }
  cout << "_______________________" << endl;
  return true;
}

int main(){
  while(solve()){}
}