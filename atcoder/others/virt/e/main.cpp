#include<bits/stdc++.h>
using namespace std;

bool ok(vector<int> R, int target, int initial){
  int N = R.size();
}



int main(){
  int N, x, y;
  cin >> N >> x >> y;
  vector<int> A(N);
  vector<int> R, C;
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(i%2==0&&i!=0) C.push_back(A[i]);
    else if(i%2==1) R.push_back(A[i]);
  }
  //ok(R, y, 0);
  //ok(C, x, A[0]);
  cout << (ok(R, y, 0)&&ok(C, x, A[0])?"Yes":"No") << endl;
}