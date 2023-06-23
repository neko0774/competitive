#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int num=0;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    num += A.at(i);
  }
  int ave=num/N;
  for(int i=0;i<N;i++){
    cout << abs(A.at(i)-ave) << endl;
  }

}