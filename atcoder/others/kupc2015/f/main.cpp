#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct node{
  //s==0 -> num
  //s==1 -> op
  int s;
  int num;
  string op;
  node(int s, string op):s(s), op(op){};
  node(int s, int num):s(s), num(num){};
};

vector<node> conv(1<<20);
vector<int> G[1<<20];

void parse(string S, int num){
  vector<int> st;
  for(auto s: S){
    if('0'<=s&&s<='9'){
      st.push_back(--num);
      conv[num] = node(0, s-'0');
    }else{
      int ch1 = *st.rbegin();
      st.pop_back();
      int ch2 = *st.rbegin();
      st.pop_back();
      conv[--num] = node(1, s);
      G[num].push_back(ch1);
      G[num].push_back(ch2);
    }
  }
}

int main(){
  string S;
  cin >> S;
  parse(S, S.size());
}