#include <bits/stdc++.h>
using namespace std;
int NOT(int x) {
  return x^1;
}
int XOR(int x, int y) {
  return x^y;
}
int AND(int x, int y) {
  return x&y;
}
int expression(string &s, int &l, int &r, vector<int> &f) {
  if( '0' <= s[l] && s[l] <= '1' ) {
    return s[l]-'0';
  }else if( 'a' <= s[l] && s[l] <= 'd' ) {
    return f[s[l]-'a'];
  }else if( s[l] == '-' ) {
    l++;
    return NOT(expression(s, l, r, f));
  }else {
    int p, q;
    char c;
    for( int i = l+1, d = 0; i <= r-1; i++ ) {
      if( s[i] == '(' ) d++;
      if( s[i] == ')' ) d--;
      if( ( s[i] == '*' || s[i] == '^' ) && d == 0 ) c = s[i], p = i-1, q = i+1;
    }
    if( c == '*' ) {
      l++, r--;
      return AND(expression(s, l, p, f), expression(s, q, r, f));
    }
    if( c == '^' ) {
      l++, r--;
      return XOR(expression(s, l, p, f), expression(s, q, r, f));
    }
  }
  return -1;
}
int main() {
  int L = 16, rem = 1<<L;
  vector<int> ans(1<<L, -1);
  vector<vector<string>> E(L+1, vector<string>());
  vector<vector<int>> f_all(1<<4, vector<int>(4));
  for( int i = 0; i < 1<<4; i++ ) {
    for( int j = 0; j < 4; j++ ) {
      f_all[i][j] = (i>>j)&1;
    }
  }
  auto get_key = [&](string s) -> int {
    int ret = 0;
    for( int i = 0; i < 1<<4; i++ ) {
      int _l = 0, _r = (int)s.size()-1;
      ret |= expression(s, _l, _r, f_all[i])<<i;
    }
    return ret;
  };
  auto operate = [&](string s) -> void {
    int ret = get_key(s);
    if( ans[ret] == -1 ) {
      rem--;
      ans[ret] = (int)s.size();
    }
  };
  E[1] = {"0", "1", "a", "b", "c", "d"};
  for( string &s : E[1] ) {
    operate(s);
  }
  for( int l = 2; l <= L; l++ ) {
    for( string &s : E[l-1] ) {
      if( s.front() != '-' ) E[l].push_back("-"+s);
    }
    if( l >= 5 ) {
      for( int x = 1; x <= (l-3)/2; x++ ) {
        for( string &s : E[x] ) {
          for( string &t : E[l-3-x] ) {
            E[l].push_back("("+s+"*"+t+")");
            E[l].push_back("("+s+"^"+t+")");
          }
        }
      }
    }
    for( string &s : E[l] ) {
      if( rem == 0 ) break;
      operate(s);
    }
  }
  string e;
  while( true ) {
    cin >> e;
    if( e == "." ) break;
    cout << ans[get_key(e)] << endl;
  }
}