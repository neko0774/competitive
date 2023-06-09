#include<bits/stdc++.h>
using namespace std;

int solve(int x, int N, vector<int> A){
    int cnt, l, num;
    cnt=l=num=0;
    for (int r=0; r<N; r++){
        num += A[r];
        while (num>x&&r>=l){
            num -= A[l];
            l++;
        }
        cnt += r-l+1; 
    }
    return cnt;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i=0; i<N; i++){
    cin >> A[i];
    }

    int x;
    for(int i=0;i<Q;i++){
        cin >> x;
        cout << solve(x, N, A) << endl;
    }
}