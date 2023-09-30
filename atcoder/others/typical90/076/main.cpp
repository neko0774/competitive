#include<bits/stdc++.h>
using namespace std;
template<typename T>
#define ll long long

void showv(deque<T> A){
  for(auto x: A) cout << x << ' ';
  cout << endl;
}

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  ll total = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    total += A[i];
  }
  if(total%10!=0){
    cout << "No" << endl;
    return 0;
  }
  deque<ll> B;
  B.push_back(0);
  for(auto a:A)B.push_back(B[B.size()-1]+a);
  B.pop_front();
  for(int i=0;i<N;i++){
    ll v = total/10+B[0];
    B[0] = 0;
    if(v>0&&binary_search(B.begin(), B.end(), v)){
      cout << "Yes" << endl;
      return 0;
    }
    B.pop_front();
    B.push_back(B[B.size()-1]+A[i]);
  }
  cout << "No" << endl;
}