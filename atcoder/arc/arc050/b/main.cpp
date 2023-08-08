#include <bits/stdc++.h>
using namespace std;

int solve(){
  int A, B;
  cin >> A >> B;
  if(A>=B) return A-B;
}


int main(){
  int T;
  cin >> T;
  while(--T){
    cout << solve() << endl;
  }

}