#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> comb(51, vector<ll>(51, -1));

ll combination(ll a, ll b){
  if(comb[a][b]!=-1)return comb[a][b];
  if (a<b||a<0||b<0) return 0;
  if(a==b||b==0)return 1;
  comb[a][b] = combination(a-1, b)+combination(a-1, b-1);
  return comb[a][b];
}

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> V(N);
  for(int i=0;i<N;i++){
    cin >> V[i];
  }

  sort(V.rbegin(), V.rend());
  ll sum = 0;
  ll c = 0;
  for(int i=0;i<A;i++){
    sum += V[i];
    if(V[i]==V[A-1])c++;
  }
  
  ll NN = 0;
  for(auto v:V){
    if(v==V[A-1])NN++;
  }
  
  cout << setprecision(15) << (long double)sum/(long double)A << endl;
  ll ans = 0;
  if(c==A){
    for(int i=A;i<=B;i++) ans += combination(NN, i);
    cout << ans << endl;
  }else{
    cout << combination(NN, c) << endl;;
  }
}