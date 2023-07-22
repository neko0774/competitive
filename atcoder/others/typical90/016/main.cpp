#include <iostream>
using namespace std;

int main(){
  long N, A, B, C;
  cin >> N;
  cin >> A >> B >> C;
  long ans = 1000000;
  for(long a=0;a<10009;a++){
    for(long b=0;b<10009;b++){
      if((N-a*A-b*B)<0)break;
      if((N-(a*A+b*B))%C==0){
        ans = min(ans, a+b+(N-(a*A+b*B))/C);
      }
    }
  }
  cout << ans << endl;
}