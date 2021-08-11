#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int power(long long b, long long p, int m){
	int res = 1;
	while(p){
		if(p%2){
			p--;
			res = (res%m*b%m)%m;
		}
		else{
			p /= 2;
			b = (b%m*b%m)%m;
		}
	}
	return res;
}

int main(){	
	int tc;
	cin>>tc;
	while(tc--){
		long long A, B, N;
		cin>>A>>B>>N;
		if(A==B){
			cout<<(power(A, N, mod)+power(B, N, mod))%mod<<endl;
		}
		else{
			priority_queue<long long> pq;
			long long num = A-B;
			for(long long i=1; i*i<=num; i++){
				if(num%i==0){
					if((power(A, N, i)+power(B, N, i))%i==0){
						pq.push(i);
					}
					if((power(A, N, num/i)+power(B, N, num/i))%(num/i)==0){
						pq.push(num/i);
					}
				}
			}
			cout<<pq.top()%mod<<endl;
		}
	}
}
