#include<bits/stdc++.h>
using namespace std;

char words[10][10];
char first[10];

int solve(int n,int m){
	for(int i=1;i<n;i++){
		int count = 0;
		for(int j=0;j<m;j++){
			if(first[j]!=words[i][j])
				count++;
		}
		if(count>1)
			return 0;
	}
	return 1;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m ;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> words[i][j];			
			}
		}
		for(int i=0;i<m;i++)
			first[i] = words[0][i];
		
		int flag = 0;
		string ans = "";
		for(int i=0;i<m;i++){
			for(char c='a';c<='z';c++){
				first[i] = c;
				int temp = solve(n,m);
				if(temp && !flag){
					flag = 1;
					for(int k=0;k<m;k++)
						ans.push_back(first[k]); 
				} 
			}
			first[i] = words[0][i];
		}
		if(flag){
			cout << ans << endl;		
		}
		else
			cout<< -1 << endl;
		
	}
	return 0;
}
