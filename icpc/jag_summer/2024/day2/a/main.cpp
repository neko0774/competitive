#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<ll> A(N + 1), B(N + 1);
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> B[i];

  vector<ll> C(2 * N + 2);
  for(int i = 1; i <= N; i++) {
    C[i + 1] += A[i] + B[i];
    C[i + N + 1] -= A[i] + B[i];
  }
  for(int i = 1; i <= 2 * N; i++) {
    C[i] += C[i - 1];
  }
  for(int i = 2; i <= 2 * N; i++) {
    C[i] += C[i - 1];
    cout << C[i] << "\n";
  }
}