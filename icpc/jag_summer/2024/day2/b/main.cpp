#include<bits/stdc++.h>
using namespace std;

int calc(int x, int y){
  x = max(x, 0);
  y = max(y, 0);
  assert(x % 2 == y % 2);
  return x / 2 + y / 2 + (x % 2) * 2;
}

template<typename S, auto op, auto e>
struct segtree
{
  int n,log,sz;
  vector<S>d;
  void update(int p){d[p]=op(d[2*p],d[2*p+1]);}
  segtree(int m):n(m)
  {
    log=1;
    while((1<<log)<n)log++;
    sz=1<<log;
    d.resize(2*sz,e());
  }
  void set(int p, S x)
  {
    p+=sz;
    d[p]=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  S get(int p){return d[p+sz];}
  S prod(int l, int r)
  {
    l+=sz,r+=sz;
    S pl=e(),pr=e();
    while(l<r)
    {
      if(l&1)pl=op(pl,d[l++]);
      if(r&1)pr=op(d[--r],pr);
      l>>=1,r>>=1;
    }
    return op(pl,pr);
  }
};

int op(int x, int y){
  return max(x, y);
}

int e(){
  return -1e9;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  string S;
  cin >> S;
  segtree<int, op, e> front(N), back(N);
  int cnt = 0;
  for(int i = N - 1; i >= 0; i--)  {
    if(S[i] == '(') cnt++;
    else cnt--;
    back.set(i, cnt);
  }

  cnt = 0;
  for(int i = 0; i < N; i++)  {
    if(S[i] == ')') cnt++;
    else cnt--;
    front.set(i, cnt);
  }
  cout << calc(front.prod(0, N), back.prod(0, N)) << endl;;

  int M = 0;
  int f_add = 0, b_add = 0;
  segtree<int, op, e> back_second(N);
  for(int i = 0; i < N; i++){
    if(S[i] == '('){
      f_add++;
      b_add++;
    }else{
      f_add--;
      b_add--;
    }
    front.set(i, e());
    back.set(i, e());
    back_second.set(i, b_add);
    M = max(M, 0) + (S[i] == ')'?1:-1);
    int first_par = max(front.prod(0, N), cnt + M) + f_add;
    int last_par = max(back_second.prod(0, N), back.prod(0, N) + b_add);
    cout << calc(first_par, last_par) << endl;
  }
}