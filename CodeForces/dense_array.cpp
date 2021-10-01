#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		int res = 0;
		for(int i=1; i<n; i++){
			float max_= max(arr[i], arr[i-1]);
			float min_ = min(arr[i], arr[i-1]);
			if(max_/min_>2){
				res += ceil(log2(max_/min_))-1;
			}
		}
		cout<<res<<endl;
	}
}
// max_ <= min_*2^(x+1)
// x >= log(max_/min_)-1
