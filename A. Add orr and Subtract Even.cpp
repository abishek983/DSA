//https://codeforces.com/contest/1311/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int a,b ; cin >> a >> b;
        if(a==b){
            cout << 0 << endl;
            continue;
        }
        if(a>b){
            if((a&1)&&(b&1)){
                cout << 1 << endl;
                continue;
            }
            if(!(a&1)&&!(b&1)){
                cout << 1 << endl;
                continue;
            }
            cout << 2 << endl;
            continue;
        }
        else{
            if((a&1)&&!(b&1)){
                cout << 1 << endl;
                continue;
            }            
            if((b&1)&&!(a&1)){
                cout << 1 << endl;
                continue;
            }
            cout << 2 << endl;
        }
    }
    return 0;
}