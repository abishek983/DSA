//http://codeforces.com/contest/1360/problem/D

/*
	Though the question directly doesn't points out this.
	we are required to find the maximum divisor of the number n.

	Algorithm:-
		1) Run a loop till sqrt(n) as the divisors of n can be found in this range only
		2) If the divisor is X check whether it is smaller than 'k' or not.
		3) If the divisor is smaller update the answer with smallest divisor value possible

*/


#include <bits/stdc++.h>
using namespace std;


int main(){
	int t; cin >> t;
	while(t--){
		long long int ans = INT_MAX;
		long long int n,k; cin >> n >> k;
		for(long long int x=1;x*x<=n;x++){
			if(n%x==0){
				if(x<=k){
					ans = min(ans,n/x);
				}
				if(n/x<=k){
					ans = min(ans,x);			
				}
			}
		}
	cout << ans << endl;
		
	}
	return 0;
}
