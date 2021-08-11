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

ll binpower(ll base, ll e, ll mod){
	ll result = 1;
	base %= mod;
	while(e){
		if(e&1) result = mulmod(result, base, mod);
		base = mulmod(base, base, mod);
		e >>= 1;
	}
	return result;
}

bool check_composite(ll n, ll a, ll d, int s){
	ll x = binpower(a, d, n);
	if(x==1||x==n-1) return false;
	for(int r=1; r<s; r++){
		x = mulmod(x, x, n);
		if(x == n-1) return false;
	}
	return true;
}

bool isPrime(ll n, int iter=5){
	if(n<=4) return n==2||n==3;
	int s = 0;
	ll d = n-1;
	while(d&1==0){
		d >>= 1;
		s++;
	}
	for(int i=0; i<iter; i++){
		ll a = 2+rand()%(n-3);
		if(check_composite(n, a, d, s)) return false;
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
