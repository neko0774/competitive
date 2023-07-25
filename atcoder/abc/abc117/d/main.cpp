#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  long long X = 0;
  for(int i=50;i>=0;i--){//i bit
    int cnt = 0;
    for(int j=0;j<N;j++){
      if(A[j]>>i&1) cnt++;
    }
    long long num = X+((long long)1<<i);
    if(cnt*2<N&&num<=K) X = num;
  }
  long long ans = 0;
  for(auto x: A){ans += x^X;}
  cout << ans << endl;
}
