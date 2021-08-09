#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n;
	cin>>n;
	int res = n;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			res /= i;
			res *= i-1;
			while(n%i==0){
				n /= i;
			}
		}
	}
	if(n!=1){
		res /= n;
		res *= n-1;
	}
	cout<<res<<endl;
}
