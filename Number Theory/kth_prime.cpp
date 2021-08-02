#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n = 90000000;
	vector<bool> sieve(n+1, true);
	for(int i=2; i*i<=n; i++){
		if(sieve[i]){
			for(int j=i*i; j<=n; j+=i){
				if(sieve[j]){
					sieve[j] = false;
				}
			}
		}
	}
	vector<int> primes;
	for(int i=2; i<=n; i++){
		if(sieve[i]){
			primes.push_back(i);
		}
	}
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		cout<<primes[n-1]<<endl;
	}
}

