#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

int main(){
  int N, K;
  ll ans=0;
  vector<int> test;
  cin >> N >> K;
  for(int i=0;i<N;i++){
    int A, B;
    cin >> A >> B;
    test.push_back(B);
    test.push_back(A-B);
  }
  sort(test.rbegin(), test.rend());
  for(int i=0;i<K;i++){
    ans += (ll)test[i];
  }
  
  cout << ans << '\n';
}