#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string operate(string N){
  long long num=0;
  string ret="";
  for(auto s:N){
    num *= 8;
    num += (s-'0');
  }
  while(num){
    if (num%9==8)ret += '5';
    else ret += to_string(num%9);
    num/=9;
  }
  reverse(ret.begin(), ret.end());
  if(ret=="")ret="0";
  return ret;
}


int main(){
  string N;
  int K;
  cin >> N >> K;
  while(K--){
    N = operate(N);
  }
  cout << N << endl;
}