//https://codeforces.com/contest/1311/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n,p; cin >> n >> p;
        int arr[n];
        int pos[n] = {};
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<p;i++){
            int temp; cin >> temp;
            pos[--temp] = 1;
        }
        
        for(int i=0;i<n;i++){
            if(pos[i]==0)
                continue;
            int j= i ;
            while(j<n && pos[j]) ++j;
            sort(arr+i,arr+j+1);
            // cout << i << " " << j << endl;
            i = j;
        }
        bool ok= true;
        /* for(int i=0;i<n;i++)
            cout << arr[i]; */
        for(int i=0;i<n-1;i++)
            ok &= arr[i] <= arr[i+1];
        if(ok) cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}