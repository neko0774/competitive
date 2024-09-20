#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_LENGTH = 1000;

bool query(string T) {
  if(T.empty()) return true;
  if((int)T.size() > MAX_LENGTH) return false;
  cout << "?" << " " << T << endl;
  string res;
  cin >> res;
  if(res == "Invalid") assert(false);
  return (res == "Yes" || res == "y");
}

void answer(string S) {
  cout << "!" << " " << S << endl;
}

string str(deque<char> T) {
  string ret;
  while(!T.empty()) {
    ret.push_back(T.front());
    T.pop_front();
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  deque<char> T;
  const int B = 23;
  mt19937 rng(time(NULL));

  auto r = [&]() -> char { return "ab"[rng() % 2]; };
  auto flip = [&](char c) -> char { return 'a' ^ 'b' ^ c; };

  {
    int buffer = 0;
    while(true) {
      const char c = r();

      T.push_back(c);
      if(query(str(T))) {
        buffer = 0;
      }else {
        buffer++;
        T.pop_back();
        T.push_back(flip(c));
      }

      if(buffer == B) {
        if(query(str(T))) {
          buffer = 0;
          continue;
        }
        else {
          for(int i = 0; i < B; i++) {
            if(!query(str(T))) T.pop_back();
            else break;
          }
          break;
        }
      }
    }
  }

  {
    int buffer = 0;
    while(true) {
      const char c = r();

      T.push_front(c);
      if(query(str(T))) {
        buffer = 0;
      }else {
        buffer++;
        T.pop_front();
        T.push_front(flip(c));
      }

      if(buffer == B) {
        if(query(str(T))) {
          buffer = 0;
          continue;
        }
        else {
          for(int i = 0; i < B; i++) {
            if(!query(str(T))) T.pop_front();
            else break;
          }
          break;
        }
      }
    }
  }

  answer(str(T));
}