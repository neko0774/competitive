#include<bits/stdc++.h>
using namespace std;

int num(string S);
struct node{
  int left = -1;
  int right = -1;
  int par = -1;
  int value = -1;
};

int cur;
int t;
int parse(vector<node> &G, string &S){
  //parse =  "" | (parse)[num](parse)
  //num = number
  if(S[cur]!='(') return -1;

  int root = t;
  t++;
  cur++;
  int left = parse(G, S);
  //) and [
  cur += 2;
  int value = num(S);
  // ] and (
  cur += 2;
  int right = parse(G, S);
  //)
  cur++;

  G[root].left = left;
  G[root].right = right;
  G[root].value = value;
  return root;
}


int num(string S){
  int ret = 0;
  while('0'<=S[cur]&&S[cur]<='9'){
    ret *= 10;
    ret += S[cur]-'0';
    cur++;
  }
  return ret;
}

void calc(vector<node> &G1, vector<node> &G2, int cur1, int cur2){
  cout << '(';
  //cout << cur1 << ' ' << G1[cur1].left << ' ' << cur2 << ' ' << G2[cur2].left << endl;
  if(G1[cur1].left!=-1&&G2[cur2].left!=-1){ 
    calc(G1, G2, G1[cur1].left, G2[cur2].left);
  }
  cout << ')';
  cout << '[' << G1[cur1].value + G2[cur2].value << ']';
  cout << '(';
  if(G1[cur1].right!=-1&&G2[cur2].right!=-1){
    calc(G1, G2, G1[cur1].right, G2[cur2].right);
  }
  cout << ')';
}

int main(){

  string S1, S2;
  cin >> S1;
  cin >> S2;
  vector<node> G1(1<<20), G2(1<<20);
  cur = 0;
  t = 0;
  int root1 = parse(G1, S1);
  cur = 0;
  t = 0;
  int root2 = parse(G2, S2);
  assert(root1==root2);
  calc(G1, G2, root1, root2);
  cout << endl;
}