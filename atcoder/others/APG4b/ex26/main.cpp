#include <bits/stdc++.h>
using namespace std;

void read_var()



int main(){
    int N;
    cin >> N;

    unordered_map<string, int> ret_num;
    unordered_map<string, vector<int>> ret_vec;
        

    for(int i=0;i<N;i++){
        string tmp;
        cin >> tmp;
        if (tmp=="int"){
            read_int()
        }else if(tmp=="print_int"){
            //todo
        }else if(tmp=="vec"){
            //todo
        }else{
            //todo
        }
    }


}