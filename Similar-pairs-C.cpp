// http://codeforces.com/contest/1360/problem/C 

// first check the number of odd and even numbers
// if the count of odd/even numbers is even then the answer is YES
// else sort the array and check if any two adjacent elements have a difference of 1


#include <bits/stdc++.h>
using namespace std;

//function to return if it's possible to get the desired result 
string possible(int arr[],int n){
	for(int i=1;i<n;i++){
		if(arr[i]-arr[i-1]==1){
			return "YES";
		}
	}
	return "NO";
}


int main(){
	int t; cin >> t;
	while(t--){
		int n,count=0; cin >> n ;
		int arr[n];
		for(int i=0;i<n;i++){
			cin >> arr[i];
			if(arr[i]&1)
				count++;
		}
		
		if(count%2==0){
			cout << "YES" << endl;		
		}
		else{
			sort(arr,arr+n);
			cout << possible(arr,n) << endl; 			
		}
		
	}
	return 0;
}
