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
  //pointerを使わないとき
  int par = -1;
  int left = -1;
  int right = -1;

  //pointerを使う
  //node *par;
  //node *left;
  //node *right;

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

void print(node cur){
  if(cur.s==0) cout << cur.num;
  if(cur.left!=-1)print(G[cur.left]);
  if(cur.right!=-1)print(G[cur.right]);
  if(cur.s==1) cout << cur.op;
}

int main(){
  string S;
  cin >> S;
  int root = build(S);
  int N = S.size();
  for(int i=0;i<N;i++){
    swap(G[i].left, G[i].right);
    //cout << G[i].s << ' ' << G[i].left << ' ' << G[i].right << endl;
  }
  print(G[root]);
  cout << endl;
}