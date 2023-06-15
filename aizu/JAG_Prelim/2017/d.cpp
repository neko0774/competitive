#include <bits/stdc++.h>
using namespace std;
constexpr int L_MAX = 1<<20;
struct segtree{
    int N;
    vector<int> a;
    void set(int i, int v) {
        i += N;
        a[i] = v;
        while( i > 1 ) {
            i >>= 1;
            a[i] = min(a[(i<<1)|0], a[(i<<1)|1]);
        }
    }
    int prod(int l, int r) {
        int ret = L_MAX;
        l += N, r += N;
        while( l < r ) {
            if( l&1 ) ret = min(ret, a[l++]);
            if( r&1 ) ret = min(ret, a[--r]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
    segtree(int _N, int V_INIT) {
        N =_N;
        a.resize(2*N, V_INIT);
    }
};
bool solve() {
    int N, M;
    cin >> N >> M;
    if( N == 0 && M == 0 ) return false;
    vector<int> s(N);
    for( int i = 0; i < N; i++ ) {
        cin >> s[i];
    }
    auto f = [](int X, int L, int S) -> int {
        if( S >= L+X ) return 0;
        else return max(1, X-abs(L-S));
    };
    s.push_back(1<<30);
    int ok = s[0], ng = s[N-1]+1;
    while( ok+1 < ng ) {
        int X = (ok+ng)/2;
        cout << ok << " " << X << " " << ng << endl;
        segtree dp(L_MAX, L_MAX);
        dp.set(0, 0);
        dp.set(1, 0);
        auto get = [&](int i) -> int {
            return dp.prod(i, L_MAX);
        };
        for( int L = 1; L <= s[N-1]; L++ ) {
            cout << get(L) << " ";
            auto itr_l = lower_bound(s.begin(), s.end(), L), itr_r = next(itr_l);
            int nxt_l = min(L_MAX-1, L+f(X, L, *itr_l)), nxt_r = min(L_MAX-1, L+f(X, L, *itr_r));
            dp.set(nxt_l, min(get(nxt_l), get(L)+1));
            dp.set(nxt_r, min(get(nxt_r), get(L)+1));
        }cout << endl;
        cout << s[N-1] << endl;
        if( M <= get(s[N]-X+1) && get(s[N]-X+1) < L_MAX ) ok = X;
        else ng = X;
    }
    cout << ok << endl;
    return true;
}
int main() {
    while( solve() ) {}
}