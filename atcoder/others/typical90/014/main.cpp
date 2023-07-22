#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int j=0;j<N;j++){
    cin >> B[j];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  long ans=0;
  for(int i=0;i<N;i++){
    ans += (long)abs(A[i]-B[i]);
  }
  cout << ans << endl;

}