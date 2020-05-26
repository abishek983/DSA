//https://codeforces.com/contest/1360/problem/E

#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;

char mat[MAX][MAX];

string solve(int n){
	int flag = 1;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(mat[i][j]=='1'){
				flag  = mat[i+1][j]-'0' || mat[i][j+1]-'0';
				if(!flag)
					return "NO";			
			}
		}
	}
	return "YES";
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n ;
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				mat[i][j] = '0';
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> mat[i][j];
			}
		}
		cout << solve(n) << endl;
	}
	return 0;
}



