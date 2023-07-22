#include <iostream>
#include <vector>
using namespace std;
bool is_good(vector<int> ary){
  int n = 0;
  for(auto i: ary){
    n += i;
    if(n<0) return false;
  }
  if(n==0) return true;
  return false;
}

int main(){
  int N;
  cin >> N;
  for(int i=0;i<1<<N;i++){
    vector<int> number(N);
    for(int j=0;j<N;j++){
      if(i>i&1) number.push_back(1);
      else number.push_back(-1);
    }
    if(is_good(number)){
      for(auto n: number) cout << (n==1) ? '(' : ')';
      cout << '\n';
    }
  }
}
