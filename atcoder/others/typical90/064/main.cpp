#include<iostream>
#include<vector>
using namespace std;
#define ll long long

void show(vector<ll> d){
  for(auto i: d) cout << i << ' ';
  cout << endl;
}


int main(){
  int N, Q;
  cin >> N >> Q;
  vector<ll> dif;
  ll lst=0;
  ll ans = 0;
  dif.push_back(0);
  cin >> lst;
  for(int i=0;i<N-1;i++){
    int tmp;
    cin >> tmp;
    dif.push_back(tmp-lst);
    ans += abs(dif[i+1]);
    lst = tmp;
  }
  dif.push_back(0);
  for(int i=0;i<Q;i++){
    int L, R;
    ll V;
    cin >> L >> R >> V;
    ll before=abs(dif[L-1])+abs(dif[R]);
    if(L>=2)dif[L-1]+=V;
    if(R<=N-1)dif[R]-=V;
    ll after=abs(dif[L-1])+abs(dif[R]);
    ans += after-before;
    cout << ans << endl;
  }
}