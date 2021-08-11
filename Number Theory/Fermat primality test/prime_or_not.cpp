#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll mulmod(ll a, ll b, ll c){
	ll x = 0, y = a%c;
	while(b > 0){
		if(b%2 == 1){
			x = (x+y)%c;
		}
		y = (y*2LL)%c;
		b /= 2;
	}
	return x%c;
}

ll binPower(ll a, ll n, ll mod){
	ll res = 1;
	while(n){
		if(n&1)
			res = mulmod(res, a, mod);
		n >>= 1;
		a = mulmod(a, a, mod);
	}
	return res%mod;
}

bool isPrime(ll n, int iterations=5){
	if(n<=4)
		return n==2||n==3;
	for(int i=1; i<=iterations; i++){
		ll a = 2+rand()%(n-3);
		ll res = binPower(a, n-1, n);

		if(res!=1) return false;
	}
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		if(isPrime(n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
