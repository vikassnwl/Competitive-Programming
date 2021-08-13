#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int power(int a, int n){
	int res = 1;
	while(n){
		if(n%2) res = (res*1LL*a)%mod;
		n /= 2;
		a = (a*1LL*a)%mod;
	}
	return res;
}

int fact(int n){
	int res = 1;
	for(int i=2; i<=n; i++){
		res = (res*1LL*i)%mod;
	}
	return res;
}

int C(int n, int k){
	int res = fact(n);
	res = (res*1LL*power(fact(k), mod-2))%mod;
	res = (res*1LL*power(fact(n-k), mod-2))%mod;
	return res;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin>>n>>m;
	cout<<C(2*m+n-1, n-1);
}
