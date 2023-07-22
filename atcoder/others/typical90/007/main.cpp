#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  int N,Q;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  cin >> Q;
  sort(A.begin(), A.end());
  for(int j=0;j<Q;j++){
    int q;
    cin >> q;
    auto i = lower_bound(A.begin(), A.end(), q);
    if (i==A.begin()) cout << abs(q-*i) << endl;
    else cout << min(abs(q-*i), abs(q-*(i-1))) << endl;
  }
}