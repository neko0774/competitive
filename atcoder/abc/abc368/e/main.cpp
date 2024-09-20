#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N, M;
  cin >> N >> M;
  vector<ll> X(M);
  cin >> X[0];
  vector<tuple<ll, int, int, ll, ll, ll>> trains(M);
  vector<map<ll, ll>> time(N);
  for(int i=0;i<M;i++){
    int a, b;
    ll s, t;
    cin >> a >> b >> s >> t;
    a--;
    b--;
    trains[i] = make_tuple(t, a, b, s, t, i);
  }
  time[get<2>(trains[0])].insert({-get<4>(trains[0]), get<4>(trains[0]) + X[0]});
  sort(trains.begin(), trains.end());
  for(auto[key, a, b, s, t, idx]: trains){
    if(idx == 0) continue;
    ll dif = max(time[a].lower_bound(-s)->second - s, 0LL);
    if(time[b].lower_bound(-t)->second < t + dif){
      time[b].insert({-t, t + dif});
    }
    X[idx] = dif;
  }
  for(int i=1;i<M - 1;i++){
    cout << X[i] << ' ';
  }
  cout << X[M - 1] << endl;
}