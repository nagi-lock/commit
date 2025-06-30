#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	vector<int> v(n+1, true);
	// index -1 chal rahe hai
	
	for(int i = 2; i<= n+1; i++){
		if(v[i]) continue;
		else{
			for(int ind = i*i; ind<=n+1; ind+=i){
				v[i] = false;
			}
		}
	}



}

int main(){

	int n = 9;
	solve(n);
	return 0;
}