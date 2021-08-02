#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n = 1000000;
	vector<bool> sieve(n+1, true);
	sieve[0] = sieve[1] = false;
	for(int i=2; i*i<=n; i++){
		if(sieve[i]){
			for(int j=i*i; j<=n; j+=i){
				if(sieve[j]){
					sieve[j] = false;
				}
			}
		}
	}
	vector<int> pp(n+1);
	int cnt = 0;
	for(int i=2; i<=n; i++){
		if(sieve[i]){
			cnt++;
		}
		if(sieve[cnt]){
			pp[i] = 1;
		}
		pp[i] += pp[i-1];
	}
	int tc;
	cin>>tc;
	while(tc--){
		int l, r;
		cin>>l>>r;
		cout<<pp[r]-pp[l-1]<<endl;
	}
}
