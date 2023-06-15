#include <bits/stdc++.h>
using namespace std;

bool in(vector<int> p, vector<int> q){
    return p[0] < q[0] && p[1] < q[1] && p[2] < q[2];
}

int main(){
    int n; 
    cin>>n;
    vector<vector<int> > list(n,vector<int>(3));
    vector<int> v(n,1);
    int V=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>list[i][j];
            v[i]*=list[i][j];
        }
        sort(list[i].begin(),list[i].end());
        V+=v[i];
    }
    vector<int> memo(n);
    for(int i=0; i<n; i++)memo[i]=i;
    int ans=V;
    do{
        int res=V;
        for(int i=0; i<n-1; i++){
            if(in(list[i],list[i+1])){
                res-=v[i];
            }
        }
        ans=min(ans,res);
    }while(next_permutation(memo.begin(),memo.end()));
    cout << ans <<endl;
}