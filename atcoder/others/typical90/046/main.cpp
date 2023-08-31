#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
  int N;
  cin >> N;

  unordered_map<int, long long> A, B, C;
  for(int i=0;i<N;i++){
    long long a;
    cin >> a;
    A[a%46]++;
  }
  for(int i=0;i<N;i++){
    long long a;
    cin >> a;
    B[a%46]++;
  }
  for(int i=0;i<N;i++){
    long long a;
    cin >> a;
    C[a%46]++;
  }
  long long ans=0;
  for(int a=0;a<46;a++){
    for(int b=0;b<46;b++){
      for(int c=0;c<46;c++){
        if((a+b+c)%46==0)ans+=A[a]*B[b]*C[c];
      }
    }
  }
  cout << ans << endl;
}