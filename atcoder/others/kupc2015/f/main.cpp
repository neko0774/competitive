#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct node{
  //s==0 -> num
  //s==1 -> op
  int s;
  int num;
  char op;
  int ord;
  int par = -1;
  int left = -1;
  int right = -1;

  node(){}
  //演算子の追加
  node(int _s, char _op):s(_s), op(_op){}
  //数字の追加 
  node(int _s, int _num):s(_s), num(_num){}
  //演算子の追加 子供の追加も同時に行う
  node(int _s, char _op, int l, int r):s(_s), op(_op), left(l), right(r){}
  //数字の追加 子供の追加も同時に行う
  node(int _s, int _num, int l, int r):s(_s), num(_num), left(l), right(r){}
};

vector<node> G(1<<20);

int build(string S){
  //受け取った逆ポーランド記法の文字列から木構造を作成する
  //返り値は作成した木のroot
  int cur = 0;
  stack<int> st;
  for(auto s: S){
    if('0'<=s&&s<='9'){
      G[cur] = node(0, s-'0');
    }else{
      int right = st.top(); st.pop();
      int left = st.top(); st.pop();
      G[cur] = node(1, s, left, right);
      G[left].par = cur;
      G[right].par = cur;
    }
    st.push(cur);
    cur++;
  }
  assert(st.size()==1);
  return st.top();
}


int main(){
  string S;
  cin >> S;
  int root = build(S);
  int N = S.size();
  string ans;
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int x = q.front();q.pop();
    if(G[x].s==0)ans.push_back(G[x].num+'0');
    else{
      ans.push_back(G[x].op);
      q.push(G[x].left);
      q.push(G[x].right);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}