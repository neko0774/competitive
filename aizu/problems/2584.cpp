#include<bits/stdc++.h>
using namespace std;
int cur;
char letter(string &S, int v);

const string ary = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


string parse(string &S){
  //cout << cur << ' ' << S[cur] << endl;
  string ret;
  while(S[cur]=='+'||S[cur]=='-'||('A'<=S[cur]&&S[cur]<='Z')){
    //return letter length of 1;
    ret +=  letter(S, 0);
  }
  if(S[cur]=='['){
    string r;
    cur++;//[
    r = parse(S);
    cur++;//]
    reverse(r.begin(), r.end());
    ret += r;
  }
  //cout << cur << ' ' << S[cur] << ' ' << S.size() << endl;
  if(cur<S.size()&&S[cur]!=']') ret += parse(S);
  return ret;
}


char letter(string &S, int v){
  if(S[cur]=='+'||S[cur]=='-'){
    v += (S[cur] == '+'? 1 : -1);
    cur++;
    return letter(S, v);
  }
  char ans = ary[(S[cur] - 'A' + v + 26*3) % 26];
  cur++;
  return ans;
}

bool solve(){
  string S;
  cin >> S;
  if(S==".") return false;
  int N = S.size();
  vector<int> cnt;
  for(int i=0;i<N;i++){
    if(S[i]=='?')cnt.push_back(i);
  };
  string ans = "#";
  if(cnt.size()==0){
    cur = 0;
    ans = parse(S);
  }else{
    if(cnt.size()==1){
      for(char s1: ary){
        S[cnt[0]] = s1;
        cur = 0;
        if(ans=="#") ans = parse(S);
        else ans = min(ans, parse(S));
      }
    }else if(cnt.size()==2){
      for(char s1: ary){
        for(char s2: ary){
          S[cnt[0]] = s1;
          S[cnt[1]] = s2;
          cur = 0;
          if(ans=="#") ans = parse(S);
          else ans = min(ans, parse(S));
        }
      }
    }else{
      for(char s1: ary){
        for(char s2: ary){
          for(char s3: ary){
            S[cnt[0]] = s1;
            S[cnt[1]] = s2;
            S[cnt[2]] = s3;
            cur = 0;
            if(ans=="#") ans = parse(S);
            else ans = min(ans, parse(S));
          }
        } 
      }
    }
  }
  cout << ans << endl;
  return true;
}

int main(){
  while(solve()){}
  return 0;
}