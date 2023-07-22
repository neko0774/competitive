#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
  int Q;cin >> Q;
  deque<int> q;
  vector<int> ans;
  for(int i=0;i<Q;i++){
    int t, x;
    cin >> t >> x;
    if(t==1)q.push_front(x);
    else if(t==2)q.push_back(x);
    else ans.push_back(q[x-1]);
  }
  for(auto s:ans)cout << s << '\n';
}