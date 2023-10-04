#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rotate(vector<vector<int>> &P){
  vector<
}


bool check(vector<string> &P1, vector<string> &P2, vector<string> &P3, int ax, int ay, int bx, int by){

}

int main(){
  vector<string> P1, P2, P3;
  string tmp;
  P1.push_back("..........");
  P1.push_back("..........");
  P1.push_back("..........");
  for(int i=0;i<12;i++){
    cin >> tmp;
    if(i<4)P1.push_back("..."+tmp+"...");
    else if(i<8)P2.push_back(tmp);
    else P3.push_back(tmp);
  }
  P1.push_back("..........");
  P1.push_back("..........");
  P1.push_back("..........");

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      for(int ax=0;ax<10;ax++){
        for(int ay=0;ay<10;ay++){
          for(int bx=0;bx<10;bx++){
            for(int by=0;by<10;by++){
              if(check(P1, P2, P3, ax, ay, bx, by)){
                cout << "Yes" << endl;
                return 0;
              }
            }
          }
        }
      } 
      rotate(P2);
    }
    rotate(P3);
  }
  cout << "No" << endl;
}