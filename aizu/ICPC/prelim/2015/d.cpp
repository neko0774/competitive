#include <bits/stdc++.h>
using namespace std;
void chmin(int& x, int y) {
    if( x < y ) x = y;
}
bool solve() {
    int n;
    cin >> n;
    if( n == 0 ) return false;
    vector<int> p(n);
    for( int i = 0; i < n; i++ ) {
        cin >> p[i];
    }
    int INF = 5000*n;
    vector<vector<int>> dp(n+1, vector<int>(500*n, INF)), ep(n+1, vector<int>(500*n, INF));
    dp[0][0] = 0;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j <= n; j++ ) {
            for( int k = 0; k < 500*n; k++ ) {
                
            }
        }
    }
    return true;
}
int main() {
    while( solve() == true ) {}
}