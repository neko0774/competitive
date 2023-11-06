#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  string tmp;
  pair<int, string> l, r;
  cout << 0 << endl;
  l.first = 0;
  r.first = N;
  cin >> l.second;
  r.second = l.second;
  if(r.second=="Vacant") return 0;

  while(abs(r.first-l.first)>1){
    int mid = (l.first+r.first)/2;
    string midd;
    cout << mid << endl;
    cin >> midd;
    if(midd=="Vacant"){
      return 0;
    }
    //cout << l.first << ' ' << l.second << ' ' << r.first << ' ' << r.second << ' ';
    //cout << mid << ' ' << midd << endl;
    if(((r.first-mid)%2!=0&&r.second==midd)||((r.first-mid)%2==1&&r.second==midd)){
      r.first = mid;
      r.second = midd;
    }else{
      l.first = mid;
      l.second = midd;
    }
  }
  cout << r.first << endl;
}