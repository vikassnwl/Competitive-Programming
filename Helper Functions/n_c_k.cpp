//video link -> /mnt/B238844C38841191/Ubuntu Stuff/Competitive Programming
//
//Binomial Coefficient
ll C(int n, int k){
	ll ans = 1;
	if(k>n-k) k = n-k;
	for(int i=1; i<=k; i++) ans *= (n-i+1), ans /= i;
	return ans;
}
