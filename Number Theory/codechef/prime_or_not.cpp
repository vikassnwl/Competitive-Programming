#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n = 1e7;
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
		if(!sieve[i]) primes.push_back(i);
	}

	int t, m;
	cin>>t;
	while(t--){
		cin>>m;
		int idx = lower_bound(primes.begin(), primes.end(), m)-primes.begin();
		if(m==primes[idx]) cout<<idx+1;
		else cout<<-1;
		cout<<endl;
	}
}
