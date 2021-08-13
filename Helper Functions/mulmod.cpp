ll mulmod(ll a, ll b, ll mod){
	ll x = 0, y = a%mod;
	while(b > 0){
		if(b%2 == 1){
			x = (x+y)%mod;
		}
		y = (y*2LL)%mod;
		b /= 2;
	}
	return x%mod;
}
