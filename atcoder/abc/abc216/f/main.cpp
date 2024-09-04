#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<atcoder/modint>
using mint = atcoder::modint998244353;


int main(){
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  vector<pair<int, int>>  AB(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    AB[i].first = A[i];
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
    AB[i].second = B[i];
  }

  sort(AB.begin(), AB.end());
  int MAX = AB[N - 1].first + 10;
  vector<mint> count(MAX, 0);

  mint ans;
  count[0] = 1;
  for(int i = 0;i < N;i++){

    vector<mint> ncount = count;

    for(int j=0;j<MAX;j++){
      if(j<=AB[i].first-AB[i].second) ans += count[j];
      ncount[min(MAX-5, j+AB[i].second)] += count[j];
    } 
    swap(count, ncount);

  }
  cout << ans.val() << endl;
}