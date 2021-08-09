#include<bits/stdc++.h>
using namespace std;

int phi[1000001];
void init(int maxN){
	for(int i=1; i<=maxN; i++){
		phi[i] = i;
	}
	for(int i=2; i<=maxN; i++){
		if(phi[i] == i){
			for(int j=i; j<=maxN; j+=i){
				phi[j] /= i;
				phi[j] *= i-1;
			}
		}
	}
}

int main(){	
	init(1000000);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<phi[n]<<endl;
	}
}
