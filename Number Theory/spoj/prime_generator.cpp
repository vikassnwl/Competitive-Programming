#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n = 32000;
	vector<bool> sieve(n+1);
	for(int i=2; i*i<=n; i++){
		if(!sieve[i]){
			for(int j=i*i; j<=n; j+=i){
				sieve[j] = true;
			}
		}
	}
	vector<int> primes;
	for(int i=2; i<=n; i++){
		if(!sieve[i]){
			primes.push_back(i);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		if(l==1)
			l++;
		vector<bool> seg(r-l+1);
		int i = 0;
		while(primes[i]*primes[i]<=r){
			int currPrime = primes[i];
			int base = currPrime*(l/currPrime);
			if(base<l)
				base += currPrime;
			for(int j=base; j<=r; j+=currPrime)
				seg[j-l] = true;
			if(base==currPrime)
				seg[base-l] = false;
			i++;
		}
		for(int i=0; i<=r-l; i++){
			if(!seg[i]){
				cout<<l+i<<endl;
			}
		}
		cout<<endl;
	}
}
