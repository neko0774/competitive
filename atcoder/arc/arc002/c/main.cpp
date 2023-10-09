#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  int N;
  cin >> N;
  string C;
  cin >> C;
  vector<char> key = {'A', 'B', 'X', 'Y'};
  int ans = 10000;
  for(auto a:key){
    for(auto b:key){
      for(auto c:key){
        for(auto d:key){
          int memo = 0;
          for(int i=0;i<C.size();i++){
            if(i==C.size()-1){memo++;}
            else{
              if((C[i]==a&&C[i+1]==b)||(C[i]==c&&C[i+1]==d)){i++;}
              memo++;
            }
          }
          ans = min(ans, memo);
        }
      }
    }
  } 
  cout << ans << endl;
}