#include <iostream>
#include <vector>
using namespace std;


int main(){
  long long N, P, Q;
  cin >> N >> P >> Q;
  vector<long long> A(N);
  for(long long i=0;i<N;i++){
    cin >> A[i];
    A[i]%=P;
  }
  long long ans=0;
  for(long long i=0;i<N;i++){
    for(long long j=i+1;j<N;j++){
      for(long long k=j+1;k<N;k++){
        for(long long x=k+1;x<N;x++){
          for(long long y=x+1;y<N;y++){
            if(A[i]*A[j]%P*A[k]%P*A[x]%P*A[y]%P==Q)ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}